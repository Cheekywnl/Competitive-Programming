#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int buy = prices[0];
    int maxProfit = 0;
    for(int i : prices){
        if(i < buy) buy = i;
        else if(i - buy > maxProfit) maxProfit = i - buy; 
    }
    return maxProfit;
}

int lengthOfLongestSubstring(string s) {
    int maxSubString = 0;
    int currentLength = 0;
    unordered_map<char, int> m;
    int left = 0;
    for(int i = 0; i < s.size(); i++){
        if(m.find(s[i]) != m.end()){
            maxSubString = max(maxSubString, currentLength);
            while(s[left] != s[i]){
                m.erase(s[left]);
                left++;
                currentLength--;
            }
            m.erase(s[left]);
            left++;
            currentLength--;
        }
        m[s[i]]++;
        currentLength++;
    }
    return max(maxSubString, currentLength);
}

// above is my solution, however there's no reason to have currentLength just use indexes and isntead of ++, just make the element in the map the index;

// below is the optimised version istead of keeping count of each characters occurance, make the map value w.r.t key just the index so that you can slide the pointers easily.

int lengthOfLongestSubstring(string s) {
    int maxSubString = 0;
    int currentLength = 0;
    unordered_map<char, int> m;
    int left = 0;
    for(int i = 0; i < s.size(); i++){
        if(m.find(s[i]) != m.end() && m[s[i]] >= left){
            left = m[s[i]] + 1;
        }
        m[s[i]] = i;
        maxSubString = max(maxSubString, i - left + 1);
    }
    return maxSubString;
}

// inital solution O(n^2)
int characterReplacement(string s, int k) {    
    int maxLen = 0;
    for(int i = 0; i < s.size(); i++){
        int count = k;
        int currentLen = 0;
        for(int j = i; j < s.size(); j++){
            if(s[j] != s[i]){
                if(count > 0) count--;
                else break;
            }
            currentLen++;
            maxLen = max(maxLen, currentLen);
        }
    }
    return maxLen;
}

// rtfq for the question after this...
bool checkAnagram(string s1, string s2) {
    if(s1.size() > s2.size()) return false;
    unordered_map<char, int> freq;
    for(int i = 0; i < s2.size(); i++){
        freq[s2[i]]++;
    }
    for(int i = 0; i < s1.size(); i++){
        if(freq.find(s1[i]) != freq.end()){
            freq[s1[i]]--;
        }
        else return false;
    }
    for(auto& pair : freq){
        if(pair.second < 0) return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size()) return false;
    int len = s1.size();
    unordered_map<char, int> freq;
    unordered_map<char, int> windowFreq;
    for(int i = 0; i < len; i++){
        freq[s1[i]]++;
        windowFreq[s2[i]]++;
    }
    if(windowFreq == freq) return true;
    for(int i = len; i < s2.size(); i++){
        if(windowFreq[s2[i - len]] == 0) windowFreq.erase(s2[i - len]);
        else windowFreq[s2[i - len]]--;
        windowFreq[s2[i]]++;
        if(windowFreq == freq) return true;
    }
    return false;
    // only need to check windows of length s2
    // could just put them both into hashmaps and compare
}


string minWindow(string s, string t) {
    if(t.size() > s.size()) return false;
    int len = t.size();
    unordered_map<char, int> freq;
    unordered_map<char, int> windowFreq;
    for(int i = 0; i < len; i++){
        freq[t[i]]++;
    }
    int l = 0, r = 0;
    string output = "";
    while((l <= r) && r != 0){
        if(windowFreq == freq){
            output = s.substr(l, r);
            if(windowFreq.find(s[l]) != windowFreq.end()) windowFreq[s[l]]--;
            left++;
        }
        else{
            right++;
            if(!(right.size() < s.size())) return output;
            if(windowFreq.find(s[r]) != windowFreq.end()) windowFreq[s[r]]++;
        }
    }
    return output;
}

int characterReplacement(string s, int k) {
    int maxLen = 0;
    map<char, int> freq;
    int left = 0;
    int right = 0;
    freq[s[0]]++;
    while(left < s.size() && right < s.size()){
        int highestFreq = max_element(freq.begin(), freq.end(), [](const auto &a, const auto &b) { return a.second < b.second; })->second;
        if(highestFreq + k < right - left + 1){
            freq[s[left]]--;
            left++; 
        }
        else{
            maxLen = max(maxLen, right - left + 1);

            right++;
            freq[s[right]]++;
        }
    }
    return maxLen;
}

// neetcode's solution

int characterReplacement2(string s, int k){
    int res = 0;
    unordered_set<char> charSet(s.begin(), s.end());

    for (char c : charSet){
        int count = 0; l = 0;
        for(int r = 0; r < s.size(); r++){
            if (s[r] == c){
                count++;
            }

            while((r - l + 1) - count > k){
                if(s[l] == c){
                    count--;
                }
                l++;
            }

            res = max(res, r - l + 1);
        }
    }

    return res;
}

// an even more optimal solution:


int characterReplacement3(string s, int k){
    unordered_map<char, int> count;
    int res = 0;

    int l = 0; maxf = 0;
    for(int r = 0; r < s.size(); r++){
        count[s[r]]++;
        maxf = max(maxf, count[s[r]]); // this is dynamically keeping track of the maximum nicely
        while((r - l + 1) - maxf > k){
            count[s[l]]--;
            l++;
        }
        res = max(res, r - l + 1);
    }

    return res;
}

// don't need to do pass, just check how many I've seen
bool pass(unordered_map<char, int>& m1, unordered_map<char, int>& m2){
    for(const auto& [key, val1] : m1) {
        auto it = m2.find(key);
        int val2 = it->second;
        if(val2 < val1) return false;
    }
    return true;
}

string minWindow(string s, string t) {
    if(t.size() > s.size()) return "";
    int len = t.size();
    unordered_map<char, int> freq, windowFreq;
    for(int i = 0; i < len; i++){
        freq[t[i]]++;
        windowFreq[t[i]] = 0;
    }
    int l = 0, minLen = s.size() + 1, startIdx = -1;
    for(int r = 0; r < s.size(); r++){
        windowFreq[s[r]]++;
        while(pass(freq, windowFreq)){
            if(r - l + 1 < minLen){
                minLen = r - l + 1;
                startIdx = l;
            }
            windowFreq[s[l]]--;
            l++;
        }
    }

    return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
}

string minWindow1(string s, string t){
    if(t.empty()) return "";
    unordered_map<char, int> freq, window;
    for(char c : t){
        freq[c]++;
    }
    int have = 0, need = freq.size();
    pair<int, int> res = {-1, -1};
    int resLen = INT_MAX;
    int l = 0;
    for(int r = 0; r < s.length(); r++){
        char c = s[r];
        window[c]++;

        if(freq.count(c) && window[c] == freq[c]) {
            have++;
        }

        while (have == need) {
            if((r - l + 1 ) < resLen){
                resLen = r - l + 1;
                res = {l, r};
            }

            window[s[l]]--;
            if(freq.count(s[l]) && window[s[l]] < freq[s[l]]) have--;
            l++;
        }
    }

    return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
}


// note to self a dequeue is just a double ended queue, and here its implemented to ensure monotoniciyt.
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    for(int i = 0; i < nums.size(); i++){
        if(!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

int main(){
    return 0;
}