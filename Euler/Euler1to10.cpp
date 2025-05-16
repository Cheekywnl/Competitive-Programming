#include <bits/stdc++.h>
using namespace std;

void problem1(int n){
    long long answer = 0;
    for(long long i = 1; i < n; i++){
        if(i % 3 == 0 || i % 5 == 0){
            answer += i;
        }
    }
    cout << answer << endl;
    return;
}

long long wFib(long long n){
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    return wFib(n - 1) + wFib(n - 2);
}

void problem2(){
    long long output = 0;
    long long n = 2;
    long long temp = 2;
    while(temp <= 4e6){
        output += temp;
        n += 3;
        temp = wFib(n); // doiong this so it doesn't need to double compute Fib
    }
    cout << output << endl;
    return;
}

void problem3(long long n){
    long long index = 2;
    while(n != 1){
        if(index > sqrt(n)){
            index = n;
            break;
        }
        if(n % index == 0){
            if(n / index == 1){
                break;
            }
            n /= index;
        }
        index++;
    }
    cout << index << endl;
    return;
}

bool isPalindrome(long long n){
    long long temp = n;
    long long reversedN = 0;
    while(temp > 0){
        int digit = temp % 10;
        reversedN = reversedN * 10 + digit;
        temp /= 10; 
    }
    if(n == reversedN){
        return true;
    }
    return false;
}

void problem4(){
    long long output = 0;
    for(long long i = 100; i < 1000; i++){
        for(long long j = 100; j < 1000; j++){
            if(isPalindrome(i * j)){
                if(i * j > output){
                    output = i * j;
                }
            }
        }
    }
    cout << output << endl;
    return;
}

long long gcd(long long a, long long b){
    if(a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

void problem5(){
    long long output = 6;
    // need to start at 6 i.e count = 4 since 2 > 1 ..
    long long count = 4;
    while(count < 21){
        output = output * count / gcd(output, count);
        count++;
    }
    cout << output << endl;
    return;
}

void problem6(){
    // sum of first natural numbers = n * (n + 1) / 2, for squares its n * (n + 1) * (2n + 1) / 6 
    long long output = (100 * 101 / 2) * (100 * 101 / 2) - (100 * 101 * 201 / 6);
    cout << output << endl;
    return;
}

void problem7(){
    long long count = 1;
    vector<long long> primes = {2};
    long long output = 3;
    while(count < 10001){
        bool any = false;
        for(size_t i = 0; i < primes.size(); i++){
            if(i * i > output) break;
            if(output % primes[i] == 0){
                any = true;
            }
        }
        if(!any){
            count++;
            primes.push_back(output);
        }
        output += 2;
    }
    cout << output - 2 << endl;
}

void problem8(){
    long long output = 0;
    long long adjacent = 13;
    string input = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    for(size_t i = 0; i < input.size() - adjacent; i++){
        long long current = 1;
        for(int j = i; j < adjacent + i; j++){
            current *= input[j] - '0';
        }
        if(current > output){
            output = current;
        }
    }
    cout << "Problem 8: " << output << endl;
    return;
}

void problem9(){
    vector<long long> squares;
    for(long long i = 1; i <= 1000; i++){
        squares.push_back(i * i);
    }
    for(size_t i = squares.size() - 1; i >= 0; i--){
        for(long long j = 0; j < squares.size(); j++){
            for(size_t k = j; k < squares.size(); k++){
                if(squares[i] == squares[j] + squares[k] && i + j + k + 3 == 1000){
                    cout << "Problem 9: " << (i + 1) * (j + 1) * (k + 1) << endl;
                    return;
                }
            }
        }
    }
    return;
}

void problem9optimal(){
    for(int i = 1; i < 1000; i++){
        for(int j = i + 1; j < 1000; j++){
            int k = 1000 - i - j;
            if(i * i + j * j == k * k){
                cout << "Problem 9: " << i * j * k << endl;
                return;
            }
        }
    }

    cout << "No Pythagorean Triple found." << endl;
    return;
}

void problem10(){
    long long max = 2e6;
    vector<long long> primes = {2};
    long long index = 3;
    while(index < max){
        bool any = false;
        for(size_t i = 0; i < primes.size(); i++){
            if(i * i > index) break;
            if(index % primes[i] == 0){
                any = true;
            }
        }
        if(!any){
            primes.push_back(index);
        }
        index += 2;
    }
    long long output = 0;
    for(int i = 0; i < primes.size(); i++){
        output += primes[i];
    }
    cout << "Problem 10: " << output << endl;
}

int main(){
    problem1(1000);
    problem2();
    problem3(600851475143);
    problem4();
    problem5();
    problem6();
    problem7();
    problem8();
    //problem9();
    problem9optimal();
    problem10();
    return 0;
}