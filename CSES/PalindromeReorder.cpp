#include <bits/stdc++.h>
using namespace std;

void palindrome(string s){
    unordered_map<char, int> frequencies;
    string output = "";
    string firstHalf = "";
    string secondHalf = "";
    char middle;
    bool first = false;
    /*
    for(int i = 0; i < s.size(); i++){
        if(frequencies.count(s[i])){
            frequencies[s[i]]++;
        }
        else{
            frequencies[s[i]] = 1;
        }
    }
    */
   for(char c : s){
    frequencies[c]++;
   }
   if(s.size() % 2 == 0){
    for(const auto& pair : frequencies){
        int frequency = pair.second;
        if(frequency % 2 == 1){
            cout << "NO SOLUTION";
            return;
        }
        
        while(frequency > 1){
            firstHalf += pair.first;
            secondHalf += pair.first;
            frequency -= 2;
        }
    }
    reverse(secondHalf.begin(), secondHalf.end());
    cout << firstHalf << secondHalf;
    return;
   }
   else{
    for(const auto& pair : frequencies){
        int frequency = pair.second;
        if(frequency % 2 == 1){
            if(first){
                cout << "NO SOLUTION";
                return;
            }
            else{
                middle = pair.first;
                first = true;
                frequency--;
            }
        }
        
        while(frequency > 1){
            firstHalf += pair.first;
            secondHalf += pair.first;
            frequency -= 2;
        }
    }
    reverse(secondHalf.begin(), secondHalf.end());
    cout << firstHalf << middle << secondHalf;
    return;
   }

}
int main(){
    string input;
    cin >> input;
    palindrome(input);
    return 0;
}