/*
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.
To check examples - https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1#

Approaches - 1. Dynamic Programming. O(n^2)
             2. Dynamic Programming with Binary Search. O(nlogn)
*/

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
        
        //Approach 1
        // int dp[n] = { };
        // int max_len = 0;
        // bool flag;
        
        // dp[0] = 1;
        
        // for(int i = 1; i < n; i++) {
        //     dp[i] = 1;
        //     flag = false;
        //     for(int j = 0; j < i; j++) {
        //         if(nums[i] > nums[j]) {
        //             dp[i] = max(dp[i], dp[j]);
        //             flag = true;
        //         }
        //     }
            
        //     if(flag)
        //         dp[i] += 1;
            
        //     max_len = max(max_len ,dp[i]);
        // }
        
        
        // return max_len;
        
        //Approach 2
        vector<int> v = {a[0]};
        
        for(int i = 1; i < n; i++) {
            if(a[i] > v.back())
                v.push_back(a[i]);
            else {
                int l = 0, r = v.size() - 1, mid;
                while(l <= r) {
                    mid = (l + r)/2;
                    if(mid == r)
                        break;
                    if(v[mid] == a[i])
                        break;
                    if(v[mid] < a[i] && v[mid + 1] > a[i]) {
                        mid++;
                        break;
                    }
                    else if(v[mid] > a[i])
                        r = mid;
                    else
                        l = mid + 1;
                }
                v[mid] = a[i];
            }
        }
        
        return v.size();
    }
};
