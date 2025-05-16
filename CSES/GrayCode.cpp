#include <bits/stdc++.h>
using namespace std;

long long power(int a, int b){
    int result = 1;
    while(b > 0){
        if(b % 2 == 1){
            result = a;
        }
        a = a;
        b /= 2;
    }
    return result;
}

string binary(long long j, int q){
    string output(q, '0');
    int count = 1;
    while(j > 0 && count <= q){
        if(j % 2 == 1){
            output[q - count] = '1';
        }
        else{
            output[q - count] = '0';
        }
        j /= 2;
        count++;
    }
    return output;
}

void grayCode(int q){
    long long total = 1 << q;
    // note this is the same as 2 ^ n
    for(long long i = 0; i < total; i++){
        cout << binary(i ^  (i >> 1), q) << endl;
    }
}

int main(){
    int q;
    cin >> q;
    grayCode(q);
    return 0;
}