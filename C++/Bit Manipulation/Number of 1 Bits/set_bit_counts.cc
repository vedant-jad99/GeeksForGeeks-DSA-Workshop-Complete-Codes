//Link to the problem - https://practice.geeksforgeeks.org/problems/set-bits0143/1#

#include <iostream>

using namespace std;

class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int digits = log2(N) + 1;
        int count = 0;
        
        for(;digits > 0; digits--) {
            if(N & 1)
                count++; 
            N = N >> 1;
        }
        
        return count;
    }
};
