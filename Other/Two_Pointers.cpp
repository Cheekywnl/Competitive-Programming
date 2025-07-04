#include <bits/stdc++.h>
using namespace std;

bool alphaNumeric(char c){
    if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return true;
    }
    return false;
}
bool isPalindrome(string s) {
    int leftP = 0;
    int rightP = s.size() - 1;
    while(leftP <= rightP){
        while(!alphaNumeric(s[leftP]) && leftP < rightP) leftP++;
        while(!alphaNumeric(s[rightP]) && leftP < rightP) rightP--;
        if(tolower(s[leftP]) != tolower(s[rightP])) return false; 
        leftP++; 
        rightP--;
    }
    return true;
}
// note the use of twoPointers and also the user of the tolower funcion - original idea was good ish but some minor errors.

// getting faster
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> output;
    int leftP = 0;
    int rightP = numbers.size() - 1;
    while(leftP < rightP){
        while(numbers[rightP] + numbers[leftP] < target) leftP++;
        while(numbers[rightP] + numbers[leftP] > target) rightP--;
        if(numbers[rightP] + numbers[leftP] == target){
            output.push_back(leftP + 1);
            output.push_back(rightP + 1);
            return output;
        }
    }
    return output;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    // note we can sort since thats O(nlogn) and seperate from the n^2 algorithm.
    vector<vector<int>> output;
    int start = 0;
    int len = nums.size(); // convention to just do nums.size() not nums.size() - 1
    for(int i = 0; i < len - 2; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue; // use continue instead of i++ its just safer for bounds
        else{
            int leftP = i + 1;
            int rightP = len - 1;
            while(leftP < rightP){
                int sum = nums[i] + nums[leftP] + nums[rightP];
                if(sum == 0){
                    output.push_back({nums[i], nums[leftP], nums[rightP]}); // nice way instead of making a temporary array
                    leftP++;
                    rightP--;
                    while(leftP < rightP && nums[leftP] == nums[leftP - 1]) leftP++; // skip duplicates now since we have working result
                    while(leftP < rightP && nums[rightP] == nums[rightP + 1]) rightP--; // same here
                }
                else if(sum < 0) leftP++; // twoSum approach
                else rightP--; // twoSum approach
            }
        }
    }
    return output;
}

int maxArea(vector<int>& heights) {
    int leftP = 0;
    int rightP = heights.size() - 1;
    int maximum = 0;
    while(leftP < rightP){
        int width = rightP - leftP;
        int minimum = min(heights[leftP], heights[rightP]);
        if(width * minimum > maximum) maximum = minimum * width;
        if(heights[leftP] < heights[rightP]) leftP++; // note just move the minimum height pointer thats the limiting factor
        else rightP--;
    }
    return maximum;
}

// my soltution - works but can be simplified
int trap(vector<int>& height) {
    int output = 0;
    int leftP = 0; 
    int rightP = height.size() - 1;
    int leftWall = height[leftP];
    int rightWall = height[rightP];
    while(leftP < rightP){
        if(height[leftP] < height[rightP]){
            if(leftWall > height[leftP + 1]){
                output += leftWall - height[leftP + 1];
            }
            else{
                leftWall = height[leftP + 1];
            }
            leftP++;
        }
        else{
            if(rightWall > height[rightP - 1]){
                output += rightWall - height[rightP - 1];
            }
            else{
                rightWall = height[rightP - 1];
            }
            rightP--;
        }
    }
    return output;
}

int trap1(vector<int>& height){
    int output = 0;
    int leftP = 0;
    int rightP = height.size() - 1;
    int leftWall = height[leftP];
    int rightWall = height[rightP];
    while(leftP < rightP){
        if(leftWall < rightWall){ // compare the walls not the values at indexes
            // same thing really just increment first because we will anyway then jsut compare with Walls
            leftP++;
            leftWall = max(leftWall, height[leftP]);
            output += leftWall - height[leftP];
        }
        else{
            rightP--;
            rightWall = max(rightWall, height[rightP]);
            output += rightWall - height[rightP];
        }
    }

    return output;
}

int main(){
    return 0;
}