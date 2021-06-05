"""
You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] 
represent the speed and efficiency of the ith engineer respectively.
Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.
Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 10^9 + 7.
Example:
        Input - n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
        Output - 60
        Explanation - We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). 
        That is, performance = (10 + 5) * min(4, 7) = 60.
        
        Input - n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
        Output - 68
        Explanation - This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. 
        That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
        
Constraints:
        Time complexity - O(nlogn + nlogk)
        Space complexity - O(n + k)
        1 <= <= k <= n <= 105
        speed.length == n
        efficiency.length == n
        1 <= speed[i] <= 105
        1 <= efficiency[i] <= 108
        
Note to self: This problem is very good with a strong conceptual hold. Do go through it once and note the programming paradigm.
"""

class Solution:
    def __init__(self):
        pass
    def maxPerformance(self, n, speed, efficiency, k):
        engineer = sorted(zip(efficiency, speed))
        subset, sum_speed, performance = [], 0, 0
        
        for eff, spd in engineer[::-1]:
            if len(subset) == k:
                min_ele = heappop(subset)
                sum_speed -= min_ele
    
            heappush(subset, spd)
            sum_speed += spd
            performance = max(performance, eff * sum_speed)
            
        return performance%1000000007
      
if __name__ == "__main__":
    n = int(input())
    speed = [int(i) for i in input()[1:-1].split()]
    efficiency = [int(i) for i in input()[1:-1].split()]
    k = int(input())
    
    sol = Solution()
    print(sol.maxPerformance(n, speed, efficiency, k))
