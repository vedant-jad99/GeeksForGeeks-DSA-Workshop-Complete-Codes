"""
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.
Example:
        Input - nums = [-1,0,1,2,-1,-4]
        Output - [[-1,-1,2],[-1,0,1]]
        Explanation - The sum of these triplets evaluates to zero.

        Input - nums = []
        Output - []

Constraints:
        Time complexity - O(n^2)
        Space complexity - O(n) [For storing the output]
        0 <= nums.length <= 3000
        -10^5 <= nums[i] <= 10^5
"""

class Solution:
    def threeSum(self, nums):
        if len(nums) < 3:
            return []

        nums.sort()
        n = len(nums)
        ans = []

        for i in range(1, n - 1):
            l, r = 0, n - 1
            while l < i and r > i:
                total = nums[l] + nums[i] + nums[r]
                if total == 0:
                    pair = [nums[l], nums[i], nums[r]]
                    if pair not in ans:
                        ans.append(pair)
                    l += 1
                elif total > 0:
                    r -= 1
                else:
                    l += 1
        return ans

if __name__ == "__main__":
    nums = input()
    if not nums.startswith('[') or not nums.endswith(']'):
        raise ValueError("Should start with [ and end with ]")
    else:
        nums = [int(i.strip()) for i in nums[1:-1].split(',')]
        sol = Solution()
        print(sol.threeSum(nums))
