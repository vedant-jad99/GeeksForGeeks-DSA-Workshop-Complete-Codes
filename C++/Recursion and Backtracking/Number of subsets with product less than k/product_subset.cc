//Link to the problem - https://practice.geeksforgeeks.org/problems/number-of-subsets-with-product-less-than-k/1#

#include <iostream>

using namespace std;

/* 
Approach 1 - Time = 0.7/1.6

class Solution {
  public:
    int numOfSubsets(int arr[], int N, int K) {
        // code here
        int prod = 1, index = -1;
        return subsetMake(arr, index, N, K, prod);
    }
    int subsetMake(int arr[], int index, int N, int K, int prod) {
        if(index == N && prod <= K)
            return 1;
        if(prod > K)
            return 0;
        
        int count = 0;
        for(int i = index + 1; i < N; i++) {
            if(prod * arr[i] <= K) {
                count++;
            }
            count += subsetMake(arr, i, N, K, prod * arr[i]);
        }
        return count;
    }
};
*/

//Approach 2 - Time = 0.5/1.6 (Optimized/Pruning)
class Solution {
  public:
    int numOfSubsets(int arr[], int N, int K) {
        // code here
        sort(arr, arr + N);
        
        int prod = 1, index = -1;
        return subsetMake(arr, index, N, K, prod);
    }
    int subsetMake(int arr[], int index, int N, int K, int prod) {
        if(index == N && prod <= K)
            return 1;
        if(prod > K)
            return 0;
        
        int count = 0;
        for(int i = index + 1; i < N; i++) {
            if(prod * arr[i] <= K) {
                count++;
                count += subsetMake(arr, i, N, K, prod * arr[i]);
            }
            else
                return count;
        }
        return count;
    }
};
