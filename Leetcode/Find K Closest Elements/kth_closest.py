"""
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
Example:
        Input - arr = [1,2,3,4,5], k = 4, x = 3
        Output - [1,2,3,4]
        
        Input - arr = [1,2,3,4,5], k = 4, x = -1
        Output - [1,2,3,4]

Constraints:
        Time complexity - O(nlogn + klogk)
        Space complexity - O(k)
        1 <= k <= arr.length
        1 <= arr.length <= 10^4
        arr is sorted in ascending order.
        -10^4 <= arr[i], x <= 10^4

Note: A better solution of O(logn + k) is available, will post later
"""

from math import abs

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        if len(arr) == 1:
            return arr
        ans = self.binSearch(0, len(arr) - 1, x, arr)
        
        temp = [(abs(x - arr[ans]), arr[ans])]
        for i in range(1, k + 1):
            if ans - i < 0:
                break
            temp.append((x - arr[ans - i], arr[ans - i]))
                
        for i in range(1, k + 1):
            if ans + i >= len(arr):
                break
            temp.append((arr[ans + i] - x, arr[ans + i]))
        # print(temp)
        
        ans, count = [], 0
        for i, j in sorted(temp):
            if count == k:
                break
            count += 1
            ans.append(j)
        return sorted(ans)
        
    
    def binSearch(self, l, r, key, arr):
        minDist, index = 10000000000, 0
        
        while l <= r:
            mid = (l + r)//2
            if arr[mid] == key:
                return mid
            elif minDist > abs(arr[mid] - key):
                minDist = abs(arr[mid] - key)
                index = mid
            if arr[mid] < key:
                l = mid + 1
            else:
                r = mid - 1
                    
        if arr[mid] == key:
            return mid
        return abs(arr[index] - key) < abs(arr[mid] - key) and index or mid 
