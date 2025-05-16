#include <bits/stdc++.h>
using namespace std;


long long sumOfFactors(long long n){
    long long count = 1;
    for(long long i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            count += i;
            if(i != n / i){
                count += n / i;
            }
        }
    }
    return count;
}

void problem21(){
    unordered_map<long long, long long> nToSum;

    long long output = 0;

    for(long long i = 2; i < 10000; i++){
        nToSum[i] = sumOfFactors(i);
    }

    for(const auto& pair : nToSum){
        // cout << pair.first << endl;
        long long a = pair.first;
        long long b = pair.second;
        if(a != b && nToSum.find(b) != nToSum.end() && nToSum[b] == a){
            // cout << "pair: " << a << " " << b << endl;
            output += a + b;
            nToSum[a] = 0;
            nToSum[b] = 0;
        }
    }
    cout << output << endl;
}

vector<string> splitByComma(const string& s){
    vector<string> output;
    string token;
    stringstream ss(s);

    while(getline(ss, token, ',')){
        output.push_back(token);
    }

    return output;
}

void problem22(){
    ifstream file("names.txt");
    if(!file){
        cerr << "Failed to open file.\n";
        return;
    }

    ostringstream buffer;
    buffer << file.rdbuf();
    string data = buffer.str();

    vector<string> parsedData = splitByComma(data);
    sort(parsedData.begin(), parsedData.end());
    long long output = 0;

    for(int i = 0; i < parsedData.size(); i++){
        long long temp = 0;
        for(int j = 1; j < parsedData[i].size() - 1; j++){
            temp += parsedData[i][j] - 'A' + 1;
        }
        temp *= (i + 1);
        output += temp;
    }

    cout << output << endl;
    return;
}

void problem23(){
    const int LIMIT = 28123;
    vector<int> abundantNumbers;
    vector<bool> canBeWrittenAsAnAbundantSum(LIMIT + 1, false);

    for(int i = 1; i <= LIMIT; i++){
        if(sumOfFactors(i) > i){
            abundantNumbers.push_back(i);
        }
    }

    for(int i = 0; i < abundantNumbers.size(); i++){
        for(int j = i; j < abundantNumbers.size(); j++){
            int sum = abundantNumbers[i] + abundantNumbers[j];
            if(sum <= LIMIT){
                canBeWrittenAsAnAbundantSum[sum] = true;
            }
            else{
                break;
                // not necessary to check further on.
            }
        }
    }

    long long output = 0; 
    for(int i = 1; i < canBeWrittenAsAnAbundantSum.size(); i++){
        if(!canBeWrittenAsAnAbundantSum[i]){
            output += i;
        }
    }

    cout << output << endl;
}

void problem23BAD(){
    // not really syure if this works:
    vector<int> abundantNumbers = {12};
    long long output = 66;
    for(int i = 13; i <= 28123; i++){
        bool contains = false;
        if(sumOfFactors(i) > i){
            abundantNumbers.push_back(i);
        }
        
        for(int j = abundantNumbers.size() - 1; j >= 0; j--){
            if(abundantNumbers[j] <= i/2){
                break;
            }
            else if(find(abundantNumbers.begin(), abundantNumbers.end(), i - abundantNumbers[j]) != abundantNumbers.end()){
                contains = true;
                break;
            }
        }

        if(!contains){
            output += i;
        }
    }

    cout << output << endl;
}

long long factorial(long long n){
    long long output = 1;
    for(long long i = 1; i <= n; i++){
        output *= i;
    }
    return output;
}

void problem24(){
    long long target = 1e6 - 1;
    // need to used zero - based indexing
    vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
    string result;

    while(target > 0){
        long long count = 1;
        long long subtractionCount = 0;
        while(factorial(count + 1) <= target){
            count++;
        }
        while(target - factorial(count) >= 0){
            target -= factorial(count);
            subtractionCount++;
        }
        result += to_string(digits[subtractionCount]);
        digits.erase(digits.begin() + subtractionCount);
    }
    for(int i = 0; i < digits.size(); i++){
        result += to_string(digits[i]);
    }
    cout << result << endl;
}
// note this works for this specific problem and input however
// should just use a for loop to go over digits.
// should also just pre compute the factorial/ store it instead of recalling.
// see below

void problem24CGT(){
    long long target = 1e6 - 1;
    vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
    string result;

    for(int i = 9; i >= 0; i--){
        long long f = factorial(i);
        int index = target / f;
        result += to_string(digits[index]);
        digits.erase(digits.begin() + index);
        target %= f;
    }

    cout << result << endl;
}

unordered_map<long long, long long> memoFib;

long long fibonacci(long long n){
    if(memoFib.count(n)) return memoFib[n];
    if(n == 0) return 0;
    if(n == 1) return 1;

    return memoFib[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

// memoization is good however since we only care about the first number with 1000 digits we can use an iterative approach.

void problem25BAD(){
    // fails due to time
    string fibNumber = "";
    long long count = 1;
    while(fibNumber.size() != 1000){
        fibNumber = to_string(fibonacci(count));
        count++;
    }
    
    cout << count - 1 << endl;
}

vector<int> addition(vector<int> a, vector<int> b){
    int carry = 0;
    int maxSize = max(a.size(), b.size());

    for(int i = 0; i < maxSize; i++){
        if(i >= a.size()){
            a.push_back(0);
        }

        int digitB = (i < b.size()) ? b[i] : 0;

        a[i] = a[i] + b[i] + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }

    if(carry != 0){
        a.push_back(carry);
    }

    return a;
}

void problem25(){
    int count = 2;
    vector<int> fib1 = {1};
    vector<int> fib2 = {1};
    while(fib2.size() < 1000){
        vector<int> temp = addition(fib1, fib2);
        fib1 = fib2;
        fib2 = temp;
        count += 1;
    }
    cout << count << endl;
}

int main(){
    //problem21();
    //problem22();
    //problem23();
    //problem24();
    //problem25();
    return 0;
}