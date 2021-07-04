/*
Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.
Example:
        Input - N = 7, arr[] = {8,-8,9,-9,10,-11,12}
        Output - 22
        Explanation - Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum 
                      as 22.
        
        Input - N = 8, arr[] = {10,-3,-4,7,6,5,-4,-1}
        Output - 23
        
Constraints:
        Time complexity - O(n)
        Space complexity - O(1)
        1 <= N <= 10^6
        -10^6 <= Arr[i] <= 10^6
        
Note: This is a good problem. 
Approach: We use modified Kadane's algorithm to solve this problem. We can say that if the sum is wrapping, i.e., it is circular, we can find the total sum, and the minimum sum 
          and the maximum circular sum will be total - minimum. If the sum is non-wrapping, then it will be the max-sum. 
Corner case: If all elements are negative, i.e., total sum = min_sum, then return max_sum.  
*/

#include <iostream>
#include <climits>

using namespace std;

class Solution{
    public:
    int circularSubarraySum(int arr[], int n){
        
        // your code here
        int total = 0;
        for(int i = 0; i < n; i++)
            total += arr[i];
            
        int min_val = minKadanes(arr, n), max_val = maxKadanes(arr, n);
        if(min_val == total)
            return max_val;
        return max(max_val, total - min_val);
    }
    int minKadanes(int arr[], int n) {
        int look_ahead = 0, min_sum = INT_MAX;
        for(int i = 0; i < n; i++) {
            look_ahead  += arr[i];
            min_sum = min(min_sum, look_ahead);
            look_ahead = min(0, look_ahead);
        }
        return min_sum;
    }
    int maxKadanes(int arr[], int n) {
        int look_ahead = 0, max_sum = INT_MIN;
        for(int i = 0; i < n; i++) {
            look_ahead  += arr[i];
            max_sum = max(max_sum, look_ahead);
            look_ahead = max(0, look_ahead);
        }
        return max_sum;
    }
};
