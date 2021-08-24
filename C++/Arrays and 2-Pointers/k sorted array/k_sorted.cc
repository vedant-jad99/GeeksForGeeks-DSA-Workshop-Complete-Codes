//Link to the problem - https://practice.geeksforgeeks.org/problems/k-sorted-array1610/1#

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k)
    {
        //code here.
        int arr1[n];
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
            arr1[i] = arr[i];
        
        sort(arr1, arr1 + n);
        for(int i = 0; i < n; i++) 
            m.insert({arr1[i], i});
        
        for(int i = 0; i < n; i++) {
            // cout<<arr[i]<<" "<<m.find(arr[i])->second<<"\n";
                
            if(abs(i - m.find(arr[i])->second) > k) {
                return "No";
            }
        }
        return "Yes";
    }
};
