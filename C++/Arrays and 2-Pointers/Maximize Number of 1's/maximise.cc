/*
Link to the question - https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1#
*/

#include <iostream>

using namespace std;

class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int l = 0, r = 0, temp = 0, longest = 0;
        while(r < n) {
            if(arr[r] == 1 || temp < m) {
                if(arr[r] == 0)
                    temp++;
                longest = max(longest, r - l + 1);
                r++;
            }
            else {
                while(arr[l] != 0)
                    l++;
                l++;
                
                temp--;
                longest = max(longest, r - l + 1);
                // cout<<r<<" "<<l<<"\n";
            }
        }
        
        return longest;
    }  
};
