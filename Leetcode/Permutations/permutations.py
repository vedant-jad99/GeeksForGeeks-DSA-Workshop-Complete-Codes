"""
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Example:
        Input - nums = [1,2,3]
        Output - [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
  
        Input - nums = [0,1]
        Output - [[0,1],[1,0]]
        
Constraints:
        Time complexity - O(n!)
        Space complexity - O(n!) [For storing answers only]        
        1 <= nums.length <= 6
        -10 <= nums[i] <= 10
        All the integers of nums are unique.
"""

class Solution:
    def permute(self, nums):
        def generate(arr, i, n):
            if i == n - 1:
                permutations.append(arr[:])
                return
            
            for j in range(i, n):
                arr[i], arr[j] = arr[j], arr[i]
                generate(arr, i + 1, n)
                arr[i], arr[j] = arr[j], arr[i]
            return
        
        permutations = []
        generate(nums, 0, len(nums))
        return permutations

if __name__ == "__main__":
    nums = input()
    if not nums.startswith('[') or not nums.endswith(']'):
        raise ValueError("Should start with [ and end with ]")
    else:
        nums = [int(i.strip()) for i in nums[1:-1].split(',')]
        sol = Solution()
        sol.permute(nums)

        print(nums)
