'''
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array 
nums = [0,1,2,4,5,6,7] might become:
[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
Example:
        Input - nums = [3,4,5,1,2]
        Output - 1
        Explanation - The original array was [1,2,3,4,5] rotated 3 times.
        
        Input - nums = [4,5,6,7,0,1,2]
        Output - 0
        Explanation - The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Constraints:
        Time complexity - O(logN)
        Space complexity - O(1)
'''

def findMin(arr):
    l = 0
    r, n = len(arr) - 1, len(arr) - 1
    
    if(n == 0):
        return arr[0]
    elif(n == 1):
        return min(arr[1], arr[0])
    
    while l <= r:
        m = l + (r - l)//2
        if arr[m] < arr[m - 1]:
            return arr[m]
        elif arr[m] > arr[m + 1]:
            return arr[m + 1]
        elif arr[m] > arr[n]:
            l = m + 1
        else:
            r = m - 1

if __name__ == '__main__':
    in_list = [int(i.strip()) for i in input()[1:-1].split(',')]
    print(findMin(in_list))