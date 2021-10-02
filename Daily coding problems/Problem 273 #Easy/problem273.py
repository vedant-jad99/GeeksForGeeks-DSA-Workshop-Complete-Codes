class Solution:
    def fixedPoint(arr, n):
        l, r = 0, n - 1
        while l <= r:
            mid = (l + r)//2
            if arr[mid] == mid:
                return True
            
            if arr[mid] > mid:
                r = mid - 1
            else:
                l = mid + 1
                
       return False
