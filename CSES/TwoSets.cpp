#include <iostream>
#include <vector>
using namespace std;

void twoSets(long long n){
    long long firstVectorSum = 0;
    long long secondVectorSum = 0;
    vector<long long> firstVector, secondVector;
    for(long long i = n; i > 0; i--){
        if(firstVectorSum <= secondVectorSum){
            firstVectorSum += i;
            firstVector.push_back(i);
        }
        else{
            secondVectorSum += i;
            secondVector.push_back(i);
        }
    }
    if(firstVectorSum != secondVectorSum){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << firstVector.size() << endl;
    for(size_t i = 0; i < firstVector.size(); i++){
        cout << firstVector[i] << " ";
    }
    cout << endl << secondVector.size() << endl;;
    for(size_t i = 0; i < secondVector.size(); i++){
        cout << secondVector[i] << " ";
    }
    cout << endl;
    return;
}

int main(){
    long long q;
    cin >> q;
    twoSets(q);
    return 0;
}