#include <iostream>
using namespace std;

void WeirdAlgorithm (long long k){
    cout << k << " ";
    while(k != 1){
        if(k % 2 == 0){
            k /= 2;
        }
        else{
            k *= 3;
            k++;
        }
        cout << k << " ";
    }
    return;
}

int main(){
    long long k;
    cin >> k;
    WeirdAlgorithm(k);
    return 0;
}