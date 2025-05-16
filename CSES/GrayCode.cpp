#include <bits/stdc++.h>
using namespace std;

long long power(int a, int b){
    int result = 1;
    while(b > 0){
        if(b % 2 == 1){
            result *= a;
        }
        a *= a;
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
    long long n = power(2, q);
    cout << binary(0, q) << endl;
    int count = 1;
    long long temp = 1;
    while(temp < n){
        cout << binary(temp , q) << endl;
        temp += power(2, count);
        count++;
    }
    long long temp2 = n - 2;
    count = 1;
    while(temp2 > 0){
        cout << binary(temp2, q) << endl;
        temp2 -= power(2, count);
        count++;
    }
    return;
}

int main(){
    int q;
    cin >> q;
    grayCode(q);
    return 0;
}