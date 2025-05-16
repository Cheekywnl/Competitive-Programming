#include <iostream>
#include <vector>
using namespace std; 

/*
This function has O(n) time complexity we can reduce that down to O(1)
The sum is (1 + 2(1 + 2 + ... + n - 1))
Therefore the whole thing is 1 + n * (n - 1)
long long weirdFib(long long n){
    long long count = 1;
    long long output = 1;
    while(count != n){
        output += 2 * count;
        count++;
    }
    return output;
}
*/

long long weirdFib(long long n){
    return 1 + (n - 1) * n;
}

long long numberSprial(long long row, long long column){
    if(row > column){
        // if the bigger one is row, we have to move left
        if(row % 2 == 0){
            return (weirdFib(row) + row - column);
        }
        return (weirdFib(row) - row + column);
        row = 0;
    }
    else if(row == column){
        return weirdFib(row);
    }
    else{
        // if the columns are bigger than the rows we have to move up
        if(column % 2 == 0){
            return (weirdFib(column) - column + row);
        }
        return (weirdFib(column) + column - row);
    }
    return -1; 
    // this shouldn't happen.
}

int main(){
    long long q, row, column;
    cin >> q;
    vector<long long> output;
    while(q--){
        cin >> row >> column;
        output.push_back(numberSprial(row, column));        
    }
    for(size_t i = 0; i < output.size(); i++){
        cout << output[i] << endl;
    }
    //cout << weirdFib(row) << endl;
    return 0;
}
