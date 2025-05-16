#include <bits/stdc++.h>
using namespace std;

int recurring_cycle_length(int d){
    unordered_map<int, int> remainder_position;
    int remainder = 1;
    int pos = 0;

    while(remainder != 0 && !remainder_position.count(remainder)){
        remainder_position[remainder] = pos;
        remainder = (remainder * 10) % d;
        pos++; 
    }

    if(remainder == 0) return 0;
    return pos - remainder_position[remainder];
}

void problem26(){
    int max = 0; 
    int index = 0;
    for(int i = 1; i < 1000; i++){
        if(recurring_cycle_length(i) > max){
            max = recurring_cycle_length(i);
            index = i;
        }
    }

    cout << index << endl;
}

unordered_map<long long, bool> primes;

bool isPrime(long long n){
    if(n <= 1) return false;
    if(n == 2) return true;
    for(int i = 3; i <= sqrt(n); i += 2){
        if(n % i == 0){
            return false;
        } 
    }
    return true;
}

long long value(int i, int j, long long n){
    return n * n + i * n + j;
}

void problem27(){
    int max = 0;
    int a, b;

    for(int i = -999; i < 1000; i++){
        for(int j = -999; j < 1000; j++){
            long long n = 0;
            bool prime = true;
            while(prime){
                long long current = value(i,j, n);
                if(current < 2){
                    prime = false;
                }
                else if(primes.count(current)){
                    prime = primes[current];
                }
                else{
                    prime = isPrime(current);
                    primes[current] = prime;
                }
                n++;
            }
            n--;
            if(n > max){
                max = n;
                a = i;
                b = j;
            }

        }
    }
    cout << a * b << endl;
}

void problem28(){
    vector<long long> squares;
    for(int i = 1; i <= 1001; i += 2){
        squares.push_back(i*i);
    }
    long long output = 1;
    for(int i = 1; i < squares.size(); i++){
        // 1 should be 3, 2 should be 5, 3 should be 7 i.e difference is 2 * i + 1 - 1
        int difference = 2 * i;
        for(int j = 0; j < 4; j++){
            output += squares[i] - j * difference;
        }
    }

    cout << output << endl;
}

void problem28_optimized(){
    // i.e computing the values on the fly, reduing space complexity to O(1), same time complexity
    long long output = 1;
    for(int i = 3; i <= 1001; i+= 2){
        long long square = i * i;
        output += square + (square - (i - 1)) + (square - 2 * (i - 1)) + (square - 3 * (i - 1));
    }
    cout << output << endl;
}

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

vector<pair<int, int>> exponentials(int n){
    vector<pair<int, int>> output;
    for(int i = 2; i <= n/2; i++){
        // i.e the largest pair we need to find/ make is 32^6 = 64^5
        for(int j = 1; j < 6; j++){
            for(int k = 2; k < 7; k++){
                if(power(i, k) == power(n, j)){
                    output.push_back(make_pair(j, k));
                }
            }
        }
    }
    return output;
}

void problem29(){
    // this works but is really scuffed
    long long output = 0;
    vector<vector<bool>> unique (101, vector<bool> (101, true));
    vector<vector<pair<int, int>>> exponential (101);

    /*
    exponential[100] = {make_pair(1, 2)};
    exponential[81] = {make_pair(1, 2), make_pair(1, 4), make_pair(3, 4)};
    exponential[64] = {make_pair(1, 2), make_pair(1,3), make_pair(1, 6), make_pair(2, 3), make_pair(5,6)};
    exponential[49] = {make_pair(1, 2)};
    exponential[36] = {make_pair(1,2)};
    exponential[32] = {make_pair(4, 5), make_pair(3, 5), make_pair(2, 5), make_pair(1, 5)};
    exponential[27] = {make_pair(1, 3), make_pair(2, 3)};
    exponential[25] = {make_pair(1, 2)};
    exponential[16] = {make_pair(1, 4), make_pair(1, 2), make_pair(3, 4)};
    exponential[9] = {make_pair(1, 2)};
    exponential[8] = {make_pair(1, 3), make_pair(2, 3)};
    exponential[4] = {make_pair(1, 2)};
    */

    for(int i = 4; i < exponential.size(); i++){
        exponential[i] = exponentials(i);
    }

    for(int i = 2; i < exponential.size(); i++){
        for(int j = 0; j < exponential[i].size(); j++){
            int count = 1;
            int index = exponential[i][j].first;
            int times = exponential[i][j].second;
            while(count <= 100 / times){
                unique[i][count * index] = false;
                count++;
            }
        }
    }
    /*
    for(int i = 2; i <= 100; i++){
        for(int j = 2; j <= 100; j++){
            long long current = power(i, j);
            if(current <= 100){
                int count = 1;
                while(count * j <= 100){
                    unique[current][count] = false;
                    count++;
                }
            }
        }
    }
    */
// only numbers we should really care for are 4, 8, 9, 16, 25, 27, 32, 36, 49, 64, 81, 100
// i.e check for all numebers 2, 100 which are exponential
// create a function which checks these numbers/ for 64 gives 32, 16, 8, 4, 2
// 64 ^ 5 = 32 ^ 6, therefore for(int i = 6; i <= 100; i += 6), 64[i] = false
// do this for all 'factors' of 64  
// e.g 64 overlaps with 32 9 times, 16 6 times, 8 5 times, 4 4 times, 2 3 times e.t.c
// therfore 
    for(int i = 2; i < unique.size(); i++){
        for(int j = 2; j < unique[i].size(); j++){
            if(unique[i][j]){
                output++;
            }
        }
    }

    cout << output << endl;
}

void problem30(){
    vector<int> fifthPowers;
    int output = 0;
    for(int i = 0; i < 10; i++){
        fifthPowers.push_back(power(i, 5));
    }
    for(int i = 2; i < 400000; i++){
        int temp = i;
        long long count = 0;
        while(temp > 0){
            count += fifthPowers[temp % 10];
            temp /= 10;
        }
        if(count == i){
            output += count;
        }
    }
    cout << output << endl;
}

int main(){
    //problem26();
    //problem27();
    //problem28();
    //problem29();
    //problem30();
    return 0;
}