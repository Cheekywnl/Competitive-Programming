#include <iostream>
#include <map>
using namespace std;

// this funciton just finds the most repeated char in a string not what the question is asking.
void repetitionsRTFQ(string s){
    map<char, int> dict;
    for(size_t i = 0; i < s.size(); i++){
        auto it = dict.find(s[i]);
        if(it != dict.end()){
            it->second++;
        }
        else{
            dict.insert({s[i], 1});
        }
    }
    int max = 0;
    for(auto it = dict.begin(); it != dict.end(); ++it){
        if(it -> second > max){
            max = it -> second;
        }
    }

    cout << max << endl;
}

void repetitions(string s){
    long long max = 0;
    long long current = 1;
    for(size_t i = 0; i < s.size() - 1; i++){
        if(s[i] == s[i + 1]){
            current++;
        }
        else{
            if(current > max){
                max = current;
            }
            current = 1;
        }
    }
    if(current > max){
        max = current;
    }
    cout << max << endl;
}
int main(){
    string input;
    cin >> input;
    repetitions(input);
    return 0;
}