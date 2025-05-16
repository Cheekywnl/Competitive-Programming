#include <bits/stdc++.h>
using namespace std;

/*

*/

void towerOfHanoi(int q){
    int movesCount = 0;
    vector<string> moves;
    stack<int> l;
    stack<int> m;
    stack<int> r;

    for(int i = q; i > 0; i--){
        l.push(i);
    }
    
    

    cout << movesCount << endl;
    for(int i = 0; i < moves.size(); i++){
        cout << moves[i] << endl;
    }
    return;
}

int main(){
    int q;
    cin >> q; 
    towerOfHanoi(q);
    return 0;
}