#include <bits/stdc++.h>
using namespace std;

void problem11(){
    long long output = 0;
    vector<vector<int>> grid;
    vector<string> lines;

    for(int i = 0; i < 20; i++){
        string line;
        getline(cin, line);
        lines.push_back(line);
    }

    for(int i = 0; i < lines.size(); i++){
        stringstream ss(lines[i]);
        int number;
        vector<int> numbers;
        while(ss >> number){
            numbers.push_back(number);
        }
        grid.push_back(numbers);
    }

    // all horizontal fours
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 16; j++){
            long long current = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
            if(current > output){
                output = current;
            } 
        }
    }
    
    // all vertical fours
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 20; j++){
            long long current = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
            if(current > output){
                output = current;
            }
        }
    }
    // all top left -> bottom right diagonal fours
    for(int i = 0; i < 16; i++){
        for(int j  = 0; j < 16; j++){
            long long current = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j +2] * grid[i + 3][j + 3];
            if(current > output){
                output = current;
            }
        }
    }

    // all bottom left -> top right diagonal fours
    for (int i = 3; i < 20; i++) {
        for (int j = 0; j < 17; j++) {
            long long current = grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3];    
            if(current > output){
                output = current;
            }
        }
    }

    /*
    this works
    however note that (i + 1, j + 1) is going down and to the right, then doing:
    (i - 1, j - 1) will just go over the same node, hence we want something like (i + 1, j - 1)
    */

    cout << "Problem 11: " << output << endl;
    return;
}


void problem12(){
    long long output;
    long long triangularNumber = 1;
    long long count = 2;
    while(true){
        long long divisors = 2;
        for(long long i = 1; i <= sqrt(triangularNumber); i++){
            if(triangularNumber % i == 0){
                divisors+=2;
            }  
        }
        if((long long)sqrt(triangularNumber) * (long long)sqrt(triangularNumber) == triangularNumber){
            divisors--;
        }
        if(divisors > 500){
            output = triangularNumber;
            break;
        }
        triangularNumber += count;
        count++;
    }
    cout << "Problem 12: " << output << endl;
    return;
}
/*
Note do 1 -> sqrt(n) for faster times. 
Also check if the number is a square
*/

void problem13(){
    long long output = 0;
    vector<string> lines;
    for(int i = 0; i < 100; i++){
        string line;
        getline(cin, line);
        lines.push_back(line);
    }

    for(int i = 50; i > 0; i -= 10){
        for(int j = 0; j < 100; j++){
            cout << lines[j] << endl;
            output += stoll(lines[j].substr(i - 10, 10));
        }
        if(i != 10){
            output /= 10000000000LL;
        }
        else{
            while(output >= 10000000000LL){
                output /= 10;
            }
        }
    }

    cout << output << endl;
    return;
}

void problem14(){
    long long max = 0;
    long long output = 1;
    for(long long i = 1; i < 1000000; i++){
        long long count = 1;
        long long temp = i;
        while(temp != 1){
            if(temp % 2 == 0){
                temp /= 2;
            }
            else{
                temp = temp * 3 + 1;
            }
            count++;
        }
        if(count > max){
            max = count;
            output = i;
        }
    }   

    cout << output << endl;
    return;
}

void problem15Bad(long long n){
    vector<vector<long long>> grid(n, vector<long long>(n));
    for(int i = 1; i <= n; i++){
        grid[n - i][n - 1] = i + 1;
        grid[n - 1][n - i] = i + 1;
    }
    for(long long i = n - 2; i >= 0; i--){
        for(long long j = n - 2; j >= 0; j--){
            grid[i][j] = grid[i][j + 1] + grid[i + 1][j];
        }
    }

    cout << grid[0][0] << endl;
}

/*
This is a nice dynamic programming solution however there is a more optimal solution which uses combinatorics
Since for each position we can either move down or right for a given positon so 2.
Since each down/ right is unique, it goes to 2nCn = 2n!/n!n!
*/


void problem15(long long n){
    long long output = 2;
    long long count = 1;
    while(count <= n){
        output *= (2 * n - count);
        output /= count;
        count++;
    }
    cout << output << endl;
    return;
}

int main(){
    //problem11();
    //problem12();
    //problem13();
    problem15(20);
    return 0;
}