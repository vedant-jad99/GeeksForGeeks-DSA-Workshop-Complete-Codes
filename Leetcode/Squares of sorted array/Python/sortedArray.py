''' 
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each 
number sorted in non-decreasing order.
Ex. Input: nums = [-4,-1,0,3,10]
    Output: [0,1,9,16,100]
    Explanation: After squaring, the array becomes [16,1,0,9,100]. After sorting, it becomes [0,1,9,16,100].

    Input: nums = [-7,-3,2,3,11]
    Output: [4,9,9,49,121]   

Constraints - 
    1 <= nums.length <= 10^4
    -10^4 <= nums[i] <= 10^4
    nums is sorted in non-decreasing order.
'''

#O(nlogn) solution
def sorted_array(nums):
    squares = [a**2 for a in nums]
    return sorted(squares)

if __name__ == '__main__':
    n = input()
    n = n.split(',')
    if len(n) == 1:
        n = n[0].split()
    nums = [int(a) for a in n]
    
    print(sorted_array(nums))
