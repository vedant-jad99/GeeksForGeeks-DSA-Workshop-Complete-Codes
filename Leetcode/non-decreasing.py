'''
Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at 
most one element.
We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that 
(0 <= i <= n - 2).
Example:
        Input - nums = [4,2,3]
        Output - true
        Explanation - You could modify the first 4 to 1 to get a non-decreasing array.

        Input - nums = [4,2,1]
        Output - false       

Constraints:
        Time Complexity - O(n)
        Space Complexity - O(1)
        n == nums.length
        1 <= n <= 10^4
        -10^5 <= nums[i] <= 10^5
'''

def checkPossibility(nums):        
        n = len(nums)
    
        #Will always be true if only one element or two elements in array.
        if n == 1:
            return True
        if n == 2:
            return True

        '''
        For every element we will check if it is less than previous as it will violate decreasing order. If it is
        violating, we can replace it with:
        1. the previous element if it is less than element before previous, i.e, if a[i] < a[i - 1] and a[i] < a[i - 2]
        2. else we will replace the previous element with the current element
        We will increase the counter for violation. If there is another violation, then we will exit loop.        
        '''         
        counter = 0
        for i, _ in enumerate(nums[1:], 1):
            if nums[i] < nums[i - 1]:
                if i == 1:
                    nums[i - 1] = nums[i]
                elif nums[i - 2] > nums[i]:
                    nums[i] = nums[i - 1]
                else:
                    nums[i - 1] = nums[i]
                
                counter += 1
                        
        return counter <= 1

if __name__ == '__main__':
    tests = int(input())
    for test in range(tests):
        list_in = [int(i) for i in input()[1:-1].split(',')]
        print(str(checkPossibility(list_in)).lower())