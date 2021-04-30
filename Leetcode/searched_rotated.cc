/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such 
that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or 
-1 if it is not in nums.
Example:
        Input - nums = [4,5,6,7,0,1,2], target = 0
        Output - 4
        Explanation - O is at 4th index

        Input - nums = [4,5,6,7,0,1,2], target = 3
        Output - -1

Constraints:
        Time complexity - O(logN)
        Space complexity - O(1)
        1 <= nums.length <= 5000
        -10^4 <= nums[i] <= 10^4
        All values of nums are unique.
        nums is guaranteed to be rotated at some pivot.
        -10^4 <= target <= 10^4
*/

#include <iostream>
#include <vector>

using namespace std;

int findMinIndex(vector<int> &);
int findEle(vector<int>, int, int, int);

int search(vector<int>& nums, int target) {
    if(nums.size() == 1 && nums[0] != target)
        return -1;
    if(nums[0] == target)
        return 0;
    if(nums[nums.size() - 1] == target)
        return nums.size() - 1;
        
    int n = nums.size() - 1, index = findMinIndex(nums);
    
    if(target < nums[n])
        return findEle(nums, index, n, target);
    return findEle(nums, 0, index, target);
}
int findMinIndex(vector<int> &nums) {
    int l = 0, h = nums.size() - 1, n = h - 1, m = 0;

    while(l < h) {
        m = l + (h - l)/2;
        if(m < n && nums[m] > nums[m + 1])
            return m + 1;
        if(m > 0 && nums[m] < nums[m - 1])
            return m;
            
        if(nums[m] > nums[n])
            l = m + 1;
        else
            h = m;
    }
    return m;
}   
int findEle(vector<int> nums, int beg, int end, int target) {
    int l = beg, h = end, m;
    
    while(l < h) {
        m = l + (h - l)/2;
        if(nums[m] == target)
            return m;
        
        if(nums[m] < target)
            l = m + 1;
        else
            h = m;
    }
    return -1;
}

int main() {
    int n, target, in;
    cin>>n>>target;

    vector<int> nums;

    for(int i = 0; i < n; i++) {
        cin>>in;
        nums.push_back(in);
    }

    cout<<search(nums, target);
}