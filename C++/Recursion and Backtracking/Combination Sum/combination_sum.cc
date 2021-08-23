//Link to the problem - https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> solution;
        int value = 0;
        vector<int> sums;
        
        unordered_set<int> s(A.begin(), A.end());
        vector<int> A_copy(s.begin(), s.end());
        sort(A_copy.begin(), A_copy.end());
        
        recurse(B, value, A_copy, sums, solution, 0);
        return solution;
    }
    void recurse(int target, int value, vector<int> A, vector<int> sums, vector<vector<int>> &solution, int start_index) {
        if(value == target) {
            solution.push_back(sums);
            return;
        }
        if(value > target)
            return;
        
        for(int i = start_index; i < A.size(); i++) {
            sums.push_back(A[i]);
            recurse(target, value + A[i], A, sums, solution, i);
            sums.pop_back();
        }
        return;
    }
};
