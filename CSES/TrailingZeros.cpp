#include <bits/stdc++.h>

using namespace std;

long long factorial(long long n){
    if(n <= 1){
        return 1;
    }
    return n * factorial(n - 1);
}

long long trailingZerosBad(long long n){
    long long output = 0;
    long long number = factorial(n);
    while(number % 10 == 0){
        number /= 10;
        output++;
    }
    return output;
}

long long zeros(long long n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 2;
    }
    return 10 * zeros(n - 1) + 1;
}

// < 6 = 1, <= 10 = 2, < 100 = 21, < 1000 = 211, 10000 = 2111, 100000 = 21111,
// This is the wrong approach, just consider for each value, is how many times  can we divide it by 5.
/*
Create a functoin to that intakes an integer n and returns the integer 1, 2, 21 e.t.c
Done
Find the largest power of 10 that the number n is greater than
*/

/*
long long trailingZeros(long long n){
    long long output = 0;
    while(n >= 10){
        long long power = 1;
        while(10 * power <= n){
            power *= 10;
        }
        n -= power;
        output += zeros((long long)log10(power));
    }
    if(n > 5 && n < 10){
        output++;
    }
    return output;
}
*/

/*
long long trailingZeros(long long n){
    long long count = 0;
    for(long long i = 1; i <= n; i++){
        long long j = i;
        while(j % 5 == 0){
            j /= 5;
            count++;
        }
    }
    return count;

}

we can still do better
*/

long long trailingZeros(long long n){
    long long count = 0;
    for(long long i = 5; n / i >= 1; i *= 5){
        count += (n / i);
    }
    return count;
}


int main(){
    long long q;
    cin >> q;
    cout << trailingZeros(q) << endl;
    return 0;
}