//Link to the problem - https://practice.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

//*****************************************************************************
//                               IMPORTANT
//*****************************************************************************


/*Approach 1 - TLE: Find all substrings and add them
Time - O(n^2)
*/

/*Approach 2 - Accepted: DP
Let sum{} be an array such that sum[i] = sum of all substrings till i, eg.:
123, sum = {1, 14, 149}, i.e., sum[0] = 1, sum[1] = 2 + 12, sum[2] = 3 + 23 + 123
Now, we can notice that, sum[1] = 2 + 10 + 2 = 2 + 10 * 1 + 2 = 2 * 2 + 10 * sum[0].
Similarly, sum[2] = 3 * 3 + 10 * (2 * 2 + 10) = 3 * 3 + 10 * sum[1]

So, our DP array will be, sum[i] = sum[i - 1] * 10 + i * digit[i]
Time - O(n)
Space - O(n)
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        int MOD = 1000000007;
        long long sum[s.length()] = { };
        long long total = (int)s[0] - 48;
        
        sum[0] = (int)s[0] - 48;
        for(int i = 1; i < s.length(); i++) {
            sum[i] = (((i + 1) * ((int)s[i] - 48))%MOD + (10 * sum[i - 1])%MOD)%MOD;
            total = (total + sum[i])%MOD;
        }
        
        return total;
    }
};
