/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given 
target value. If target is not found in the array, return [-1, -1].
Example:
        Input - nums = [5, 7, 7, 8, 8, 10], target = 8
        Output - [3, 4]
        Explanation - Starting index of 8 is 3 and last index is 4

        Input - nums = [5, 7, 7, 8, 8, 10], target = 9
        Output - [-1, -1]
        Explanation - 9 is not present in nums

Constraints:
        Time Complexity - O(logN)
        Space Complexity - O(1)
        0 <= nums.length <= 10^5
        -10^9 <= nums[i] <= 10^9
        nums is a non-decreasing array.
        -10^9 <= target <= 10^9
*/

//Algorithm used here is binary search

#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>

using namespace std;

void ret_indices(vector<int> &, int, int, int, int &, int &);

vector<int> searchRange(vector<int>& nums, int target) {
    int s_ind = INT_MAX, e_ind = INT_MIN;

    if(nums.size() == 0)
        return vector<int> {-1, -1};
    ret_indices(nums, target, 0, nums.size() - 1, s_ind, e_ind);
    
    if(s_ind == INT_MAX && INT_MIN) {
        s_ind = -1;
        e_ind = -1;
    }
    vector<int> res{s_ind, e_ind};
    return res;
}
void ret_indices(vector<int> &arr, int k, int beg, int end, int &s_ind, int &e_ind) {
    int split_index = ceil((double)(end - beg)/2) - 1 + beg;

    if(beg == end && arr[end] != k)
        return;
    
    if(beg == end && arr[end] == k) {
        s_ind = min(beg, s_ind);
        e_ind = max(end, e_ind);
        return;
    }
    
    if(beg + 1 == end) {
        if(arr[beg] == k && arr[end] == k) {
            s_ind = min(beg, s_ind);
            e_ind = max(end, e_ind);
        }
        if (arr[beg] == k) {
            s_ind = min(beg, s_ind);
            e_ind = max(beg, e_ind);
        }
        if(arr[end] == k) {
            s_ind = min(end, s_ind);
            e_ind = max(end, e_ind);
        }
        return;
    }
    
    if(arr[split_index] >= k) 
        ret_indices(arr, k, beg, split_index, s_ind, e_ind);
    if(arr[split_index + 1] <= k)
        ret_indices(arr, k, split_index + 1, end, s_ind, e_ind);
}

int main() {
    int n, k;
    cin>>n>>k;

    vector<int> vec;
    int acc;
    for(int i = 0; i < n; i++) {
        cin>>acc;
        vec.push_back(acc);
    }

    vector<int> ans = searchRange(vec, k);
    for(int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<", ";

    return 0;
}
