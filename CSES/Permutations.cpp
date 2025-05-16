#include <iostream>
#include <vector>
using namespace std;

void permutations(long long q){
    if(q == 1){
        cout << q << endl;
        return; 
    }
    if(q < 4){
        cout << "NO SOLUTION" << endl;
        return; 
    }
    vector<long long> output;
    for(long long i = q - 1; i > 0; i -= 2){
        output.push_back(i);
    }
    /*
    No need for this as it will only fial if q < 4;
    if(output[output.size() - 1] + 1 == q){
        cout << "NO SOLUTION" << endl;
        return;
    }
    */
    for(long long i = q; i > 0; i -= 2){
        output.push_back(i);
    }
    for(size_t i = 0; i < output.size(); i++){
        cout << output[i] << " ";
    }
    cout << endl;
}

int main(){
    long long q;
    cin >> q;
    permutations(q);
    return 0;
}