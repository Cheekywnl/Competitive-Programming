#include <iostream>
#include <vector>
using namespace std;

void increasingArray(vector<long long> input){
    long long count = 0;
    for(size_t i = 1; i < input.size(); i++){
        if(input[i] < input[i - 1]){
            count += input[i - 1] - input [i];
            input[i] = input[i - 1];
        }
    }

    cout << count << endl;
}
int main(){
    long long q, k;
    cin >> q;
    vector<long long> input(q);
    while(q--) {
        cin >> k;
        input.push_back(k);
    }
    increasingArray(input);
    return 0;
}