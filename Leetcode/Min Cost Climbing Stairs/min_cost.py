"""
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
Example:
        Input - cost = [1,100,1,1,1,100,1,1,100,1]
        Output - 6
        Explanation - Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].
    
        Input - cost = [10,15,20]
        Output - 15

Constraints:
        Time complexity - O(n)
        Space complexity - O(1)
        2 <= cost.length <= 1000
        0 <= cost[i] <= 999
"""

class Solution:
    def __init__(self):
        pass
    def minCostClimbingStairs(self, cost):
        cost = [0] + cost
        n = len(cost) - 3
        while n >= 0:
            cost[n] = cost[n] + min(cost[n + 1], cost[n + 2])
            n -= 1
        return cost[0]
    
if __name__ == "__main__":
    cost = [int(i.strip()) for i in input()[1:-1].split(',')]
    if len(cost) < 2:
        print("Length of costs should be at least 2")
    else:
        sol = Solution()
        print(sol.minCostClimbingStairs(cost))
