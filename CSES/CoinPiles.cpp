#include <bits/stdc++.h>
using namespace std;

string coinPiles(long long a, long long b){
    bool solution = true;
    if((a + b) % 3 != 0){
        solution = false;
    }
    if(min(a, b) * 2 < max(a, b)){
        solution = false;
    }
    if(solution){
        return "YES";
    }
    else{
        return "NO";
    }
}


int main(){
    long long q, a, b;
    cin >> q;
    vector<string> output;
    while(q--){
        cin >> a >> b;
        output.push_back(coinPiles(a, b));
    }
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << endl;
    }
    return 0;
}