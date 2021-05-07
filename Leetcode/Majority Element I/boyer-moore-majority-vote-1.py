'''
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.You may assume that the majority element always exists in the array.
Example:
        Input - [2,2,1,1,1,2,2]
        Output - 2
        Explanation - 2 occurs more than 3 times
        
Constraints:
        Time complexity - O(n)
        Space complexity - O(1)
        n == nums.length
        1 <= n <= 5 * 10^4
        -2^31 <= nums[i] <= 2^31 - 1
'''

def majorityElement(nums):
    count = 0
    m = 0
    
    for i in nums:
        if count == 0:
            m = i
            count += 1
        elif m == i:
            count += 1
        else:
            count -= 1
            
    return m
    
if __name__ == "__main__":
    nums = input()
    nums = [int(i.strip()) for i in nums[1:-1].split(',')]
    
    print(majorityElement(nums))
