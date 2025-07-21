#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int upper = nums.size() - 1;
    int lower = 0;
    while(lower <= upper){   
        int mid = (upper + lower) / 2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) lower = mid + 1;
        else upper = mid - 1;
    }
    return -1;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix[0][0] > target) return false;
    int upper = matrix.size() - 1;
    int lower = 0;
    int middle;
    while(lower <= upper){
        middle = (upper + lower) / 2;
        if(target <= matrix[middle][matrix[middle].size() - 1] && target >= matrix[middle][0]) break;
        else if(matrix[middle][0] < target) lower = middle + 1;
        else upper = middle - 1;
    }

    int index = middle;
    upper = matrix[index].size() - 1;
    lower = 0;

    while(lower <= upper){
        int middle = (upper + lower) / 2;
        if(matrix[index][middle] == target) return true;
        else if(matrix[index][middle] <= target) lower = middle + 1;
        else upper = middle - 1;
    }
    return false;
}


int ceiling(int a, int b) {
    return (a + b - 1) / b;
}
// < not <= check this with just some simple cases
int minEatingSpeed(vector<int>& piles, int h) {
    int maxValue = 0;
    for(int i : piles) if(i > maxValue) maxValue = i;
    int lowerInt = 1;
    while(lowerInt < maxValue){
        int currentInt = (lowerInt + maxValue) / 2;
        int currentTime = 0;
        for(int i = 0; i < piles.size(); i++){
            currentTime += ceiling(piles[i], currentInt);
        }
        if(currentTime <= h) maxValue = currentInt;
        else lowerInt = currentInt + 1;
    }
    return maxValue;
}

// or this if you want to use <=
int minEatingSpeed2(vector<int>& piles, int h) {
    int maxValue = 0;
    for(int i : piles) if(i > maxValue) maxValue = i;
    int lowerInt = 1;
    int output = maxValue;
    while(lowerInt <= maxValue){
        int currentInt = (lowerInt + maxValue) / 2;
        int currentTime = 0;
        for(int i = 0; i < piles.size(); i++){
            currentTime += ceiling(piles[i], currentInt);
        }
        if(currentTime <= h){ 
            if(currentInt < output) output = currentInt;
            maxValue = currentInt - 1;
        }
        else lowerInt = currentInt + 1;
    }
    return output;
}

int findMin(vector<int> &nums) {
    int minimum = nums[0];
    int lower = 0;
    int upper = nums.size() - 1;
    while(lower <= upper){
        int middle = (lower + upper) / 2;
        if(nums[middle] < minimum){ 
            minimum = nums[middle];
            upper = middle - 1;
        }
        else lower = middle + 1;
    }
    return minimum;
}

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(nums[middle] == target) return middle;
        if(nums[left] <= nums[middle]){
            // left side of the array is sorted i.e
            // 1,2,3,4,5,6
            if(nums[left] <= target && target < nums[middle]) right = middle - 1;
            else left = middle + 1;
        }
        else{
            // i.e right side of the array is sorted 
            // 6,1,2,3,4,5
            if (nums[middle] < target && target <= nums[right]) left = middle + 1;
            else right = middle - 1;
        }
    }

    return -1;
}

class TimeMap {
    unordered_map<string, map<int, string>> m;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it) -> second;
    }
};



double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
    int left = 0, right = nums1.size();
    while(left <= right){
        int part1 = (left + right) / 2;
        int part2 = (nums1.size() + nums2.size() + 1) / 2 - part1;
        
        int maxl1 = (part1 == 0) ? INT_MIN : nums1[part1 - 1];
        int minr1 = (part1 == nums1.size()) ? INT_MAX : nums1[part1];

        int maxl2 = (part2 == 0) ? INT_MIN : nums2[part2 - 1];
        int minr2 = (part2 == nums2.size()) ? INT_MAX : nums2[part2];

        if(maxl1 <= minr2 && maxl2 <= minr1){
            if((nums1.size() + nums2.size()) % 2 == 0){
                return (max(maxl1, maxl2) + min(minr1, minr2)) / 2.0;
            }
            else return max(maxl1, maxl2);
        } 
        else if (maxl1 > maxl2) right = part1 - 1;
        else left = part1 + 1;
    }

    // Safety fallback (unreachable in valid cases)
    return 0.0;
}


int main(){
    return 0;
}