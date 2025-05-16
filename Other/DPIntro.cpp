#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> memoFib;
// this is a good example of memoization
// note make sure you declare a map beforehand
int fibonacci(int n) {
    if (memoFib.count(n)) return memoFib[n];
    if (n == 0) return 0;
    if (n == 1) return 1;

    return memoFib[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

unordered_map <long long, int> memoCollatz;

long long CollatzSequence(long long n) {
    if (memoCollatz.count(n)) return memoCollatz[n];
    if (n == 1) return 1;
    if(n % 2 == 0){
        return memoCollatz[n] = CollatzSequence(n/2) + 1;
    }
    else{
        return memoCollatz[n] = CollatzSequence(3 * n + 1) + 1; 
    }
}

int maxCollatz(int n){
    int max = 1;
    int maxIndex = 1;
    for(int i = 1; i <= n; i++){
        int current = CollatzSequence(i);
        if(current > max){
            maxIndex = i;
            max = current;
        }
    }

    return maxIndex;
}

// from a starting point in a grid, search all of the nodes down to the end and then all of the nodes going down to the right
// find the value of the final node, return it upwards
// pick the maximum of the left and right node and then += it upwards
// note this only works for binary like trees e.g two possible routes.
long long DFS(int row, int col, vector<vector<long long>> grid){
    if(row == grid.size() - 1){
        return grid[row][col];
    }
    
    long long leftPath = DFS(row + 1, col, grid);
    long long rightPath = DFS(row + 1, col + 1, grid);

    return grid[row][col] + max(leftPath, rightPath);
}

long long BFS(vector<vector<long long>>& triangle){
    // note this kind of only works for triangle structures.
    int n = triangle.size();
    queue<tuple<int, int, long long>> q;
    q.push({0,0, triangle[0][0]});

    while (!q.empty()) {
        auto [row, col, currSum] = q.front();
        q.pop();

        if (triangle[row][col] == 50) {
            return currSum;
        }

        if (row < n - 1) {
            return currSum; // i.e target found
        }

        if (row < n - 1) {
            // searching the left side: (actually straight down)
            q.push({row + 1, col, currSum + triangle[row + 1][col]});
            // searching the right side:
            q.push({row + 1, col + 1, currSum + triangle[row + 1][col + 1]});
        }
    }

    return -1; // i.e not found
}
int main(){
    cout << fibonacci(37) << endl;
    cout << maxCollatz(1e6) << endl;
    return 0;
}