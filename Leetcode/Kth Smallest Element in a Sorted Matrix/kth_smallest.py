"""
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
Example:
        Input - matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
        Output - 13
        Explanation - The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

        Input - matrix = [[-5]], k = 1
        Output - -5
        
Constraints:
        Time complexity - O(kLogK)
        Space complexity - O(k)
        n == matrix.length
        n == matrix[i].length
        1 <= n <= 300
        -109 <= matrix[i][j] <= 109
        All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
        1 <= k <= n2

Note: Another solution is possible with binary search. Link to the solutions - https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/
"""

from heapq import *

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        
        if k == 1:
            return matrix[0][0]
        if k == n**2:
            return matrix[n - 1][n - 1]
        
        heap = [(matrix[0][0], 0, 0)]
        while k > 0:
            val, r, c = heappop(heap)
            if r < n - 1:
                if matrix[r + 1][c] != 'N':
                    heappush(heap, (matrix[r + 1][c], r + 1, c))
                matrix[r + 1][c] = 'N'
            if c < n - 1:
                if matrix[r][c + 1] != 'N':
                    heappush(heap, (matrix[r][c + 1], r, c + 1))
                matrix[r][c + 1] = 'N'
            k -= 1 
        return val
