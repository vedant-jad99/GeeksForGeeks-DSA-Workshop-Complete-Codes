/*
Given two strings. The task is to find the length of the longest common substring.
Example:
        Input - S1 = "ABCDGH", S2 = "ACDGHR"
        Output - 4
        Explanation - The longest common substring is "CDGH" which has length 4.
        
        Input - S1 = "ABC", S2 = "ACB"
        Output - 1

Constraints:
        Time complexity - O(m*n)
        Space complexity - O(m*n)
        1<=n, m<=1000
*/

#include <iostream>
#include <string>

using namespace std;

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n][m] = { };
        int longest = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(S1[i] == S2[j]) {
                    if(i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                }        
                
                longest = max(dp[i][j], longest);
            }
        }
        
        return longest;
    }
};
