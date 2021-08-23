//Link to the problem - https://practice.geeksforgeeks.org/problems/min-cost-climbing-stairs/1#

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        cost.push_back(0);
        for(int i = 2; i < N + 1; i++) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        
        return cost[N];
    }
};
