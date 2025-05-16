#include <iostream>
using namespace std;

/*
Inefficient power algorithm
long long twoN(long long n){
    if(n == 0){
        return 1;
    }
    return 2 * twoN(n - 1);
}
*/

/*
Notice:
We are using the MOD here as we are working close to the upper limit of the long long.
If we end up going over, we get an overflow error which will just return 0.
We don't really want the exact answer for the larger answers just the mod w.r.t MOD.
Note difference between orignal power implementtaion and this one is that:
We square the base to speed up the O(n) time complexity.
*/

const long long MOD = 1e9 + 7;

long long power(long long base, long long exponent, long long mod) {
    long long result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

int main(){
    long long q;
    cin >> q;
    cout << power(2, q, MOD) << endl;
    return 0;
}