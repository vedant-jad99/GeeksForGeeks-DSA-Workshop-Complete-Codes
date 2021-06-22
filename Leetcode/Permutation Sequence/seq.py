"""
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
    1.    "123"
    2.    "132"
    3.    "213"
    4.    "231"
    5.    "312"
    6.    "321"
Given n and k, return the kth permutation sequence.
Example:
        Input - n = 3, k = 3
        Output - "213"
        Explanation - Refer above values

        Input: n = 4, k = 9
        Output: "2314"

Constraints:
        Time complexity - O(n^2)
        Space complexity - O(n)
        1 <= n <= 9
        1 <= k <= n!
"""

#Appraoch 1 - Time complexity - O(n!) [Worst case]
#Submission time - Nearly 6600 - 6800 ms 
#
# class Solution:
#     def getPermutation(self, n: int, k: int) -> str:
#         def nextPermutation(nums, n):
#             i = n - 1
#             while i > 0:
#                 if nums[i] > nums[i - 1]:
#                     j = n - 1
#                     while j >= i:
#                         if nums[j] > nums[i - 1]:
#                             nums[j], nums[i - 1] = nums[i - 1], nums[j]
#                             break
#                         j -= 1
#                     break
#                 i -= 1

#             limit = (n - i)//2
#             count = 0
#             while count < limit:
#                 nums[i + count], nums[n - count - 1] = nums[n - count - 1], nums[i + count]
#                 count += 1
#             return nums

#         def permute(n, k, iteration, string):
#             if iteration == k:
#                 return "".join(string)

#             temp = nextPermutation(string, n)
#             return permute(n, k, iteration + 1, string)
        
#         iteration, string = 1, []
#         for i in range(1, n + 1):
#             string.append(str(i))

#         return permute(n, k, iteration, string)




#Appraoch 2 - (Efficient). O(n^2) 
#Submission time - 32ms (Reduced by a factor of nearly 200!!!)
#
#Approach explanation: Given n numbers from 1 to n, if we list out all the permutations, we can see that the first digit of permutaion
#is 1 for first (n - 1)! permutations, 2 for next (n - 1)! permutations and so on. So, we can determine the first digit by doing k/(n - 1)!
#We can do the same for the second, third, fourth etc, with k being k%(n - i)! for ith iteration.

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        def factorial(n):
            if n == 2:
                return 2
            
            return n*factorial(n - 1)
        
        def returnKth(n_list, string, n, k, fact):
            if n == 0:
                return string
            
            partial_fact = fact//n
            if k%partial_fact != 0:
                index = k//partial_fact
            else:
                index = k//partial_fact - 1
            k %= partial_fact
            m = n_list.pop(index)
            return returnKth(n_list, string + m, n - 1, k, partial_fact)

        if n == 1:
            return "1"
        
        n_list = [str(i) for i in range(1, n + 1)]
        string = ""
        fact = factorial(n)
        return returnKth(n_list, string, n, k, fact)

if __name__ == "__main__":
    input_string = input()
    input_list = input_string.split(" ")
    n, k = int(input_list[0]), int(input_list[1])
    ans = Solution().getPermutation(n, k)
    print(ans)    
