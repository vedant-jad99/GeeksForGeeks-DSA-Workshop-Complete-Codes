"""
Link to the question - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3812/
"""

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        def binSearch(nums, l, r):
            if l == r:
                return r
            mid = (l + r)//2
            if nums[mid] > nums[mid + 1]:
                return binSearch(nums, l, mid)
            return binSearch(nums, mid + 1, r)
            
        
        if len(nums) == 1:
            return 0
        
        return binSearch(nums, 0, len(nums) - 1)
