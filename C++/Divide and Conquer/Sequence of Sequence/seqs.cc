/*
Link to the question - https://practice.geeksforgeeks.org/problems/sequence-of-sequence1155/1#
*/

#include <iostream>

using namespace std;

class Solution{
public:
    int numberSequence(int m, int n){
        /*
        Divide and conquer approach
        */
        if(n > m)
            return 0;
        
        if(n == 1)
            return m;
        
        return numberSequence(m/2, n - 1) + numberSequence(m - 1, n);
        
        /*
        DP approach
        */
        
        // if(n > m)
        //     return 0;
        
        // int dp[n][m + 2] = { };
        
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j <= m; j++) {
        //         if(i == 0)
        //             dp[i][j] = j;
        //         else
        //             dp[i][j] = dp[i - 1][j/2] + dp[i][j - 1];
        //     }
        // }
        
        // return dp[n - 1][m];
    }
};
