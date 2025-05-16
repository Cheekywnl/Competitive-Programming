#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
void MissingNumber(long long k){
    long long q;
    vector<long long> output(k);
    iota(output.begin(), output.end(), 1);
    for(long long i = 0; i < k - 1; i++){
        cin >> q;
        output.erase(output.begin() + q - 1);
    }
    cout << output[0];
    return;
}
The reason this isn't good is because as output is changing over time, output.erase(...) might be out of bounds eventually.    
*/

void MissingNumber(long long k){
    long long q;
    vector<bool> output(k + 1, false);
    for(long long i = 0; i < k - 1; i++){
        cin >> q;
        output[q] = true;
    }
    for(size_t i = 1; i < output.size(); i++){
        if(!output[i]){
            cout << i;
        }
    }

    return;
}

/*
chatGPT's appraoch: 
void MissingNumber(long long k) {
    long long totalXOR = 0, inputXOR = 0, q;

    // XOR of all numbers from 1 to k
    for (long long i = 1; i <= k; i++) {
        totalXOR ^= i;
    }

    // XOR of k-1 given numbers
    for (long long i = 0; i < k - 1; i++) {
        cin >> q;
        inputXOR ^= q;
    }

    // The missing number is the difference of these XORs
    cout << (totalXOR ^ inputXOR);
}
*/

int main(){
    long long k;
    cin >> k;
    MissingNumber(k);
    return 0;
}