#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char, int> smap;
    unordered_map<char, int> tmap;
    for(size_t i = 0; i < s.size(); i++){
        if(smap.find(s[i]) != smap.end()){
            smap[s[i]] = smap[s[i]] + 1;
        }
        else{
            smap.insert({s[i], 1});
        }


            
    }
    for(size_t i = 0; i < t.size(); i++){
        if(tmap.find(t[i]) != tmap.end()){
            tmap[t[i]] = tmap[t[i]] + 1;
        }
        else{
            tmap.insert({t[i], 1});
        }
    }
    return smap == tmap;
}

bool hasDuplicate(vector<int>& nums) {
    set<int> temp;
    for(size_t i = 0; i < nums.size(); i++){
        temp.insert(nums[i]);
    }
    return temp.size() != nums.size();
}

// not the most efficient see below: use unordered_set!

bool hasDuplicate(vector<int>& nums){
    unordered_set<int> temp;
    for(int num : nums){
        if (seen.count(num)){
            return true;
        }
        seen.insert(num);
    }
    return false;
}

/*
note this is more efficient since unordered_set as average case O(1) insert and lookup
therefore total time is O(n) 
unordered_set is stored as a hash set i.e a hash table, set is stored  as a balanced binary tree
time complexity of set is O(log n)  whereas unordered_set has time complexity O(1)
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    vector<int> output;
    for(int i = 0; i < nums.size(); i++){
        if(map.find(target - nums[i]) != map.end()){
            output.push_back(map[target - nums[i]]);
            output.push_back(i);
            return output;
        }
        else{
            map[nums[i]] = i;
            // note when inserting target, be sure you are doing either target - numns[i] or numms[i]
        }
    }
    return output;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<array<int, 26>, vector<string>> groups;
    for(string s : strs){
        array<int, 26> freq;
        for(char c : s){
            freq[c - 'a']++;
        }
        groups[freq].push_back(s);
    }

    vector<vector<string>> output;
    for (const auto& pair : groups){
        output.push_back(pair.second);
    }

    return output;
}

/*
note this will only work in c++ 20 or beyond since c++ 17 and before there is no default way to hash a hashmap
hence use:

struct ArrayHasher {
    size_t operator()(const array<int, 26>& arr) const {
        size_t h = 0;
        for(int x : arr){
            h ^= hash<int>()(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<array<int, 26>, vector<string>, ArrayHasher> groups;

    for (const string& s : strs) {
        array<int, 26> freq = {0};  // Initialize counts to zero
        for (char c : s) {
            freq[c - 'a']++;
        }
        groups[freq].push_back(s);
    }

    vector<vector<string>> output;
    for (const auto& pair : groups) {
        output.push_back(pair.second);
    }

    return output;
}

i.e create a hashing algorithm to hash arrays.
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    unordered_map<int, int> freq;
    for(int i : nums) freq[i]++;
    for(const auto& pair : freq){
        if(q.size() < k){
            q.push(make_pair(pair.second, pair.first));
        }
        else if(q.top().first < pair.second){
            q.pop();
            q.push(make_pair(pair.second, pair.first));
        }            
    }
    vector<int> output;
    while(!q.empty()){
        output.push_back(q.top().second);
        q.pop();
    }
    return output;
}

/*
note put the delimiter at the start along with word length
so that way even if we come into the same delimiter again we can skip it
*/

string encode(vector<string>& strs) {
    string output = "";
    for(string s : strs){
        output += to_string(s.size());
        // note the use of to_string here
        output += "#";
        output += s;
    }
    return output;
}

vector<string> decode(string s) {
    vector<string> output;
    string tempLength = "";
    for(size_t i = 0; i < s.size(); i++){
        if(s[i] != '#'){
        tempLength += s[i];
        }
        else{
            i++;
            int q = atoi(tempLength.c_str());
            // atoi expexts a c type string, use stoi instead.
            string temp = "";
            while(q--){
                temp += s[i];
                i++;
            }
            i--;
            // make sure you decrement it afterwards since you are incrementing by 1 extra.
            output.push_back(temp);
            tempLength = "";
        }
    }
    return output;
}

// to optimize:

vector<string> goodDecode(string s){
    vector<string> output;
    size_t i = 0;
    while(i < s.size()){
        size_t j = i;
        while(s[j] != '#') j++;
        int len = stoi(s.substr(i, j - 1));
        j++;
        output.push_back(s.substr(j, len));
        i = j + len;
    }
    return output;
}

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> prefix;
    vector<int> postfix;
    size_t len = nums.size();
    int pre = 1;
    int post = 1;
    for(size_t i = 0; i < len; i++){
        pre *= nums[i];
        post *= nums[len - i - 1];
        prefix.push_back(pre);
        postfix.push_back(post);
    }
    vector<int> output;
    output.push_back(postfix[postfix.size() - 2]);
    for(size_t i = 1; i < len - 1; i++){
        output.push_back(prefix[i - 1] * postfix[len - i - 2]);
    }
    output.push_back(prefix[len - 2]);
    // note think of examples to get the indexing right!
    return output;
}

// this is not optimal in terms of space complexity, don't need the extra arrays.

vector<int> goodProduceExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n, 1);

    int prefix = 1;
    for(int i = 0; i < n; i++){
        output[i] = prefix;
        prefix *= nums[i];
    }

    int postfix = 1;
    for(int i = n - 1; i >= 0; i--){
        output[i] *= postfix;
        postfix *= nums[i];
    }s
    return output;
}

bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> columns(board.size());
        vector<vector<unordered_map<char, int>>> boxes(3, vector<unordered_map<char, int>>(3));
        for(size_t i = 0; i < board.size(); i++){
            unordered_map<char, int> row;
            for(size_t j = 0; j < board[i].size(); j++){
                row[board[i][j]]++;
                columns[j][board[i][j]]++;
                boxes[i/3][j/3][board[i][j]]++;
            }   
            for(const auto& pair: row){
                if(pair.first != '.' && pair.second > 1){
                    return false;
                }
            }
        }
        for(size_t i = 0; i < board.size(); i++){
            for(const auto& pair: columns[i]){
                if(pair.first != '.' && pair.second > 1){
                    return false;
                }
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(const auto& pair: boxes[i][j]){
                    if(pair.first != '.' && pair.second > 1){
                        return false;
                    }
                }
            }
        }
    return true;
}

// notes we know that they will be of fixed size board.
bool isValidSudoku2(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> columns(9);
        vector<vector<unordered_map<char, int>>> boxes(3, vector<unordered_map<char, int>>(3));
        for(int i = 0; i < 9; i++){
            unordered_map<char, int> row;
            for(int j = 0; j < board[i].size(); j++){
                row[board[i][j]]++;
                columns[j][board[i][j]]++;
                boxes[i/3][j/3][board[i][j]]++;
            }   
            for(const auto& pair: row){
                if(pair.first != '.' && pair.second > 1){
                    return false;
                }
            }
        }
        for(int i = 0; i < 9; i++){
            for(const auto& pair: columns[i]){
                if(pair.first != '.' && pair.second > 1){
                    return false;
                }
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(const auto& pair: boxes[i][j]){
                    if(pair.first != '.' && pair.second > 1){
                        return false;
                    }
                }
            }
        }
    return true;
}

bool isValidSudoku3(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> columns(9);
        vector<vector<unordered_map<char, int>>> boxes(3, vector<unordered_map<char, int>>(3));
        for(int i = 0; i < 9; i++){
            unordered_map<char, int> row;
            for(int j = 0; j < board[i].size(); j++){
                char c = board[i][j];
                row[c]++;
                columns[j][c]++;
                boxes[i/3][j/3][c]++;
                if(c != '.' && (row[c] > 1 || columns[j][c] > 1 || boxes[i/3][j/3][c] > 1)){
                    return false;
                }
            }   
        }
    return true;
}

int longestConsecutive(vector<int>& nums) {
    int max = (int)-1e9;
    int min = (int)1e9;
    for(int i : nums){
        if(i > max){
            max = i;
        }
        if(i < min){
            min = i;
        }
    }
    vector<bool> sequence (max - min + 1, false);
    // need the + 1 to get the bounds right i.e nums = [1], would give an empty array.
    for(int i : nums){
        sequence[i - min] = true;
    }
    int output = 0;
    int temp = 0;
    for(bool i : sequence){
        if(i) temp++;
        else{
            if(temp > output) output = temp;
            temp = 0;
        }
    }
    if(temp > output){
        return temp;
    }
    return output;
}

// this is my inital solution its optimal in time complexity not space complexity, note you can use sets, O(1) lookup time
// see the below solution using unordered_set and slightly better logic to get a more optimal solution.

int longestConsecutive1(vector<int>& nums) {
    int longestSequence = 0;
    unordered_set<int> sequence(nums.begin(), nums.end());
    for(int i : sequence){
        int current = 1;
        if(sequence.find(i - 1) == sequence.end()){
            while(sequence.find(i + current) != sequence.end()) current++;
        }
        if(current > longestSequence) longestSequence = current;
    }
    return longestSequence;
}

int main(){
    return 0;
}