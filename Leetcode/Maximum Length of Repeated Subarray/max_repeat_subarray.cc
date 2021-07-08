/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
Example:
        Input - nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
        Output - 3
        Explanation - The repeated subarray with maximum length is [3,2,1].

        Input - nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
        Output - 5
        
Constraints:
        Time complexity - O(mn)
        Space complexity - O(mn)
        1 <= nums1.length, nums2.length <= 1000
        0 <= nums1[i], nums2[i] <= 100
        
Approaches: Dynamic Programming, Binary Search with check, Binary Search with Rolling Hash, Sliding Window
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int dp[n][m];
        int max_len = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = 0;
                if(nums1[i] == nums2[j]) {
                    if(i == 0 || j == 0)
                        dp[i][j] = 1;
                    else 
                        dp[i][j] = dp[i - 1][j - 1] + 1;

                     max_len = max(max_len, dp[i][j]);
                }
            }
        }
        
        return max_len;
    }
};
