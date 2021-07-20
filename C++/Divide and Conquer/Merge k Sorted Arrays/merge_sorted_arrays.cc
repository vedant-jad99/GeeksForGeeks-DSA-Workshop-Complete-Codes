/*
Link to the problem - https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1#
Time complexity - O(K^2(logK))
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        return mergeRec(arr, 0, K - 1, K);
    }
    
    vector<int> mergeRec(vector<vector<int>> &arr, int start, int end, int K) {
        if(start == end) {
            vector<int> temp;
            for(int i = 0; i < K; i++)
                temp.push_back(arr[start][i]);
        
            return temp;
        }
            
        int mid = (start + end)/2;
        vector<int> mergeLeft = mergeRec(arr, start, mid, K);
        vector<int> mergeRight = mergeRec(arr, mid + 1, end, K);
        
        return merge(mergeLeft, mergeRight);
    }
    vector<int> merge(vector<int> &mergeLeft, vector<int> &mergeRight) {
        vector<int> temp;
        
        int i = 0, j = 0;
        while(i < mergeLeft.size() && j < mergeRight.size()) {
            if(mergeLeft[i] < mergeRight[j])
                temp.push_back(mergeLeft[i++]); 
            else
                temp.push_back(mergeRight[j++]);
        }
        
        while(i < mergeLeft.size())
            temp.push_back(mergeLeft[i++]);
            
        while(j < mergeRight.size())
            temp.push_back(mergeRight[j++]);
            
        return temp;
    }
};
