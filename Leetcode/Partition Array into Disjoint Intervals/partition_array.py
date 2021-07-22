"""
Link to the question - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3823/
"""

class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        """
        Approach 1: O(n^2)
        Test cases passed: 53/56
        """        
#         for i, j in enumerate(nums[1:], 1):
#             minimum = max(nums[:i])
#             maximum = min(nums[i:])
            
#             if minimum <= maximum:
#                 return i
        
        """
        Approach 2: O(n)
        Test cases passed: All
        
        Find the subarrays such that, max(A[0:i]) <= min(A[i + 1:0])
        """
        max_arr, min_arr = [], []
        for i in nums:
            max_arr.append(0)
            min_arr.append(0)
            
        n = len(nums) - 1
        for i, j in enumerate(nums):
            if i == 0:
                max_arr[0] = nums[0]
                min_arr[n] = nums[n]
                continue
            
            max_arr[i] = max(max_arr[i - 1], nums[i])
            min_arr[n - i] = min(min_arr[n - i + 1], nums[n - i])
            
            # print(max_arr, min_arr)
            
        for i in range(0, n):
            if min_arr[i + 1] >= max_arr[i]:
                return i + 1
