/*
Link to the question - https://practice.geeksforgeeks.org/problems/adventure-in-a-maze2051/1#
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> FindWays(vector<vector<int>>&matrix){
            // Code here
            int n = matrix.size(); 
            int cost[n][n] = { };
            int dp[n][n] = { };
            
            dp[n - 1][n - 1] = 1;
            
            for(int i = n - 1; i >= 0; i--) {
                for(int j = n - 1; j >= 0; j--) {
                    if(i == n - 1 && j == n - 1)
                        continue;
                    
                    if(i == n - 1) {
                        if(matrix[i][j] == 1 || matrix[i][j] == 3)
                            dp[i][j] = dp[i][j + 1];
                    }
                    else if(j == n - 1) {
                        if(matrix[i][j] == 2 || matrix[i][j] == 3)
                            dp[i][j] = dp[i + 1][j];
                    }
                    else {
                        if(matrix[i][j] == 1)
                            dp[i][j] = dp[i][j + 1];
                        else if(matrix[i][j] == 2)
                            dp[i][j] = dp[i + 1][j];
                        else
                            dp[i][j] = (dp[i + 1][j] + dp[i][j + 1])%1000000007;
                    }
                }
            }
                
            
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(cost[i][j] == 0 && (i != 0 || j != 0))
                        continue;
                    else {
                        if(matrix[i][j] == 1) {
                            if(cost[i][j] == 0) {
                                cost[i][j] = matrix[i][j];
                                cost[i][j + 1] = matrix[i][j + 1] + cost[i][j];
                            }
                            else {
                                if(j < n - 1)
                                    cost[i][j + 1] = max(cost[i][j + 1], cost[i][j] + matrix[i][j + 1]);
                            }
                        }
                        else if(matrix[i][j] == 2) {
                            if(cost[i][j] == 0) {
                                cost[i][j] = matrix[i][j];
                                cost[i + 1][j] = matrix[i + 1][j] + cost[i][j];
                            }
                            else {
                                if(i < n - 1)
                                    cost[i + 1][j] = max(cost[i + 1][j], cost[i][j] + matrix[i + 1][j]);
                            }
                        }
                        else {
                            if(cost[i][j] == 0) {
                                cost[i][j] = matrix[i][j];
                            }
                            
                            if(i + 1 < n)
                                cost[i + 1][j] = max(cost[i + 1][j], cost[i][j] + matrix[i + 1][j]);
                            if(j + 1 < n)
                                cost[i][j + 1] = max(cost[i][j + 1], cost[i][j] + matrix[i][j + 1]);
                        }
                    }
                }
            }
            
            return vector<int> {dp[0][0], cost[n - 1][n - 1]}; 
        }
};
