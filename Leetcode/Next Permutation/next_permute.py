"""
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory.
Example:
        Input - nums = [1,2,3]
        Output - [1,3,2]

        Input - nums = [3,2,1]
        Output - [1,2,3]

Constraints:
        Time complexity - O(n)
        Space complexity - O(1)
        1 <= nums.length <= 100
        0 <= nums[i] <= 100
"""

class Solution:
    def nextPermutation(self, nums):
        n = len(nums) - 2
        index, rev = 0, n + 1

        for i in range(n,-1,-1):
            if nums[i] >= nums[i + 1]:
                continue
            else:
                j = n + 1
                while nums[j]  <= nums[i]:
                    j -= 1
                nums[j], nums[i] = nums[i], nums[j]
                index = i + 1
                break

        while index < rev:
            nums[index], nums[rev] = nums[rev], nums[index]
            index += 1
            rev -= 1

if __name__ == "__main__":
    nums = input()
    if not nums.startswith('[') or not nums.endswith(']'):
        raise ValueError("Should start with [ and end with ]")
    else:
        nums = [int(i.strip()) for i in nums[1:-1].split(',')]
        sol = Solution()
        sol.nextPermutation(nums)

        print(nums)
