"""
Given an integer array nums, return the length of the longest strictly increasing subsequence.
A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a 
subsequence of the array [0,3,1,6,2,2,7].
Example:
        Input - nums = [10,9,2,5,3,7,101,18]
        Output - 4
        Explanation - The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
        
        Input - nums = [0,1,0,3,2,3]
        Output - 4
        
Constraints:        
        Time complexity - Best - O(nlogn)
        Space complexity - O(n)
        1 <= nums.length <= 2500
        -104 <= nums[i] <= 104
        
Approaches - 1. Recusrion
             2. Dynamic Programming
             3. DP with Binary Search
"""

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        #Approach 1
#         def helper(nums, n, length, picked=None):  
#             if nums == []:
#                 return length
#             max_len = 0
#             for i in range(n):
#                 if picked is None or nums[i] > picked:
#                     max_len = max(max_len, helper(nums[i + 1:], n - i - 1, length + 1, nums[i]))
            
#             max_len = max(max_len, length)
#             return max_len
        
#         return helper(nums, len(nums), 0)
                
    
        #Approach 2
#         n, max_len = len(nums), 1
        
#         dp = [0 for _ in nums]
#         dp [0] = 1
        
#         for i in range(1, n):
#             flag = False
#             for j in range(i - 1, -1, -1):
#                 if nums[i] > nums[j]:
#                     dp[i] = max(dp[i], dp[j])
#                     flag = True
#             if flag:
#                 dp[i] += 1
#             else:
#                 dp[i] = 1
#             max_len = max(dp[i], max_len)
            
#         return max_len

        
      #Approach 3
        sub = [nums[0]]
        for i in nums[1:]:
            if i > sub[-1]:
                sub.append(i)
            else:
                l, r = 0, len(sub) - 1
                while l <= r:
                    mid = (l + r)//2
                    if mid == r:
                        break
                    if sub[mid] == i:
                        break
                    elif sub[mid] < i and sub[mid + 1] > i:
                        mid += 1
                        break
                    elif sub[mid] > i:
                        r = mid
                    else:
                        l = mid + 1
                sub[mid] = i
                print(sub)
        
        return len(sub)
            
            
            

