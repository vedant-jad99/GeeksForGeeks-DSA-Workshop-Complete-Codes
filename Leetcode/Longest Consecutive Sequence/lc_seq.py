"""
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Example:
        Input - nums = [100,4,200,1,3,2]
        Output - 4
        Explanation - The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
        
        Input - nums = [0,3,7,2,5,8,4,6,0,1]
        Output - 9

Constraints:
        Time complexity - O(n)
        Space complexity - O(n)
        0 <= nums.length <= 10^5
        -10^9 <= nums[i] <= 10^9
        
Note - Solution and explanation of problem link - https://leetcode.com/problems/longest-consecutive-sequence/solution/
"""

class Solution:
    def __init__(self):
        pass
    def longestConsecutive(self, nums):
        numset = set(nums)
        max_seq = 0
        
        for i in numset:
            if i - 1 in numset:
                continue
            
            num, count = i, 0
            while num in numset:
                num += 1
                count += 1
            
            max_seq = max(max_seq, count)
        
        return max_seq
      
    """
    Another(original) approach - O(nlogn) Time complexity
    def longestConsecutive(self, nums):
        if len(nums) == 0:
            return 0
        
        nums.sort()
        
        count, max_seq = 1, 0
        for i, _ in enumerate(nums[1:], 1):
            if nums[i] == nums[i - 1]:
                continue
            if nums[i] - nums[i - 1] == 1:
                count += 1
            else:                
                max_seq = max(max_seq, count)
                count = 1
            
        return max(count, max_seq)
    """
    
if __name__ == "__main__":
    nums = [int(i.strip()) for i in input()[1:-1].split(',')]
    sol = Solution()
    print(sol.longestConseccutive(nums))
