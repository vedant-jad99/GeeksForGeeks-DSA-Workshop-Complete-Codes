/*
Link to the question - https://practice.geeksforgeeks.org/problems/find-sum-of-different-corresponding-bits-for-all-pairs4652/1#
*/

#include <iostream>

using namespace std;

class Solution{
public:
    int countBits(int N, long long int A[])
    {
        // code here
        int MOD = 1000000007;
        int max_num = 0;
        for(int i = 0; i < N; i++) 
            if(max_num < A[i])
                max_num = A[i];
        
        long long int ans = 0;
        int digits = log2(max_num);
        for(int i = 0; i <= digits; i++) {
            int mask = 1<<i;
            long long int zeros = 0, ones = 0;
            for(int j = 0; j < N; j++) {
                if(mask & A[j])
                    ones++;
                else
                    zeros++;
            }
            
            long long int prod = (ones * zeros)%MOD;
            ans = (ans + prod)%MOD;
        } 
        
        return (2 * ans)%MOD;
    }
};
