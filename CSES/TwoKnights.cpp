#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

// Count the number of ways two knights can be placed on an nxn chessboard without attacking each other.
/*
Idea: 1x1 grid, too small, 2x2 grid, place one knight, then see where can we place the second.
Store all possible combinations as tuples for co ordinates e.g ((1,1), (1,2))
iterate over all squares adding each tuple into a set (no duplicates)
return the size of the set / 2.
*/

bool isAttacking(int i1, int j1, int i2, int j2) {
    int di = abs(i1 - i2);
    int dj = abs(j1 - j2);
    return (di == 1 && dj == 2) || (di == 2 && dj == 1);
}

long long twoKnight(long long n){
    // set<tuple<tuple<long long, long long>, tuple<long long, long long>>> coordinates;
    // we don't actually need this if we just count smart.
    int count = 0;
    for(int i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            for(long long k = i; k < n; k++){
                int j2 = (i == k) ? j + 1 : 0;
                for(long long l = j2; l < n; l++){
                    /*
                   Idea iterate over each square in turn.
                   Then for each square, iterate over all of the other squares checking the coordinates w.r.t to the first square.
                   If in bounds, then add the square to the set 
                   For a given square you need to check: 
                   8
                   7
                   6
                   5
                   4
                   3 o x x x x x x
                   2 x o x x x x x 
                   1 2 3 4 5 6 7 8 
                    */
                    if(!isAttacking(i,j,k,l)){
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

vector<long long> twoKnights(long long n){
    vector<long long> output;
    for(long long i = 1; i <= n; i++){
        output.push_back(twoKnight(i));
    }
    return output;
}

int main(){
    long long input;
    cin >> input;
    vector<long long> result = twoKnights(input);
    for(size_t i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}