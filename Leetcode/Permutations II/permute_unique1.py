"""
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
Example:
        Input - nums = [1,1,2]
        Ouput - [[1,1,2], [1,2,1], [2,1,1]]
        Explanation - These are all the unique combinations of the given array

        Input - nums = [1,2,3]
        Output - [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
        
Constraints:
        Time complexity - O(n!/(n - k)!)
        Space complexity - O(n!/(n - k)!)
        1 <= nums.length <= 8
        -10 <= nums[i] <= 10
        
Note: This is approach 1. Will be posting approach 2 soon.
"""
import sys

class Solution:
    def permuteUnique(self, nums):
        def factorial(n):
            if n == 1:
                return 1
            return n * factorial(n - 1)
        
        def findDuplicates(num):
            dup_vals, count = [], 1
            for i in range(1, len(num)):
                if num[i] == num[i - 1]:
                    count += 1
                else:
                    dup_vals.append(count)
                    count = 1
            dup_vals.append(count)
            return dup_vals
                    
        def nextPermutation(num):
            n = len(num) - 2
            index, rev = 0, n + 1
        
            for i in range(n,-1,-1):
                if num[i] >= num[i + 1]:
                    continue
                else:
                    j = n + 1
                    while num[j]  <= num[i]:
                        j -= 1
                    num[j], num[i] = num[i], num[j]
                    index = i + 1
                    break

            while index < rev:
                num[index], num[rev] = num[rev], num[index]
                index += 1
                rev -= 1
            permutations.append(num[:])
        
        nums.sort()
        fact = factorial(len(nums))
        duplicates, permutations = findDuplicates(nums), []
        for i in duplicates:
            fact = fact//factorial(i)
        
        for i in range(fact):
            nextPermutation(nums)
        return permutations

if __name__ == "__main__":
    args = sys.argv
    print(args)
    nums = [int(i.strip()) for i in args[1][1:-1].split(',')]
    sol = Solution()
    answer_list = sol.permuteUnique(nums)
    print(len(answer_list), answer_list)
