"""
Link to the problem - https://leetcode.com/explore/featured/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3960/
"""

class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        vis = [False for i in nums]
        max_chain = 0
        for ind, i in enumerate(nums):
            vis[ind] = True
            max_chain = max(max_chain, self.dfs(i, nums, vis))
        
        return max_chain
    
    def dfs(self, el, nums, vis):
        if vis[el]:
            return 1
        
        vis[el] = True
        return 1 + self.dfs(nums[el], nums, vis)
