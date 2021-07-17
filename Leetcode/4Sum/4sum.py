"""
Link to the question - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3816/
"""

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        uniques = set()
        
        for i in range(len(nums) - 3):
            for j in range(i + 1, len(nums) - 2):
                l, r = j + 1, len(nums) - 1
                while l < r:
                    total = nums[i] + nums[j] + nums[l] + nums[r]
                    if total == target:
                        uniques.add((nums[i], nums[j], nums[l], nums[r]))
                        l += 1
                    elif target < total:
                        r -= 1
                    else:
                        l += 1
                        
        return [list(i) for i in uniques]
