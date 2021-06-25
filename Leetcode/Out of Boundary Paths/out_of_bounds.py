"""
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid 
(possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it 
modulo 109 + 7.
Example:
        Input - m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
        Output - 6
        
        Input - m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
        Output - 12

Constraints:
        Time complexity - O(M*m*n)
        Space complexity - O(m*n)
        1 <= m, n <= 50
        0 <= maxMove <= 50
        0 <= startRow < m
        0 <= startColumn < n

Topic - Dynamic Programming.
Link - https://leetcode.com/problems/out-of-boundary-paths/
"""
#Approach 1 - Recursion (Time limit exceeded):

# import numpy as np
# class Solution:
#     def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
#         def pathsUtil(cost, row, col, moves):
#             if moves == 0:
#                 return 0
#             if moves == 1:
#                 return cost[row][col]
            
#             l, r, t, b = 0, 0, 0, 0
#             m, n = cost.shape
            
            
#             if col - 1 >= 0:
#                 l = pathsUtil(cost, row, col - 1, moves - 1)
#             if col + 1 < n:
#                 r = pathsUtil(cost, row, col + 1, moves - 1)
#             if row - 1 >= 0:
#                 t = pathsUtil(cost, row - 1, col, moves - 1)
#             if row + 1 < m:
#                 b = pathsUtil(cost, row + 1, col, moves - 1)
            
#             return l + b + r + t
        
#         costMat, cost = self.costMatrix(m, n), 0
#         for i in range(1, maxMove + 1):
#             cost += pathsUtil(costMat, startRow, startColumn, i)
#             # print(cost)
#         return cost
        
        
#     def costMatrix(self, m, n):
#         cost = np.zeros((m, n), dtype="Int64")
#         for i in range(m):
#             for j in range(n):
#                 if i - 1 < 0:
#                     cost[i][j] += 1
#                 if i + 1 >= m:
#                     cost[i][j] += 1
#                 if j - 1 < 0:
#                     cost[i][j] += 1
#                 if j + 1 >= n:
#                     cost[i][j] += 1
#         print(cost)
#         return cost

#Approach 2 - Dynamic Programming

import numpy as np
class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        dp, mod = np.zeros((m, n), dtype="Int64"), 10**9 + 7
        dp[startRow][startColumn], count = 1, 0
        for moves in range(maxMove):
            temp = np.zeros((m, n), dtype="Int64")
            for i in range(m):
                for j in range(n):
                    if i == m - 1:
                        count = (count + dp[i][j])%mod
                    if i == 0:
                        count = (count + dp[i][j])%mod
                    if j == n - 1:
                        count = (count + dp[i][j])%mod
                    if j == 0:
                        count = (count + dp[i][j])%mod
                        
                    l, r, t, b = 0, 0, 0, 0
                    if i > 0:
                        t = dp[i - 1][j]
                    if i < m - 1:
                        b = dp[i + 1][j]
                    if j > 0:
                        l = dp[i][j - 1]
                    if j < n - 1:
                        r = dp[i][j + 1]
                        
                    temp[i][j] = ((l + r)%mod + (t + b)%mod)%mod
            
            dp = temp.copy()
        return count
