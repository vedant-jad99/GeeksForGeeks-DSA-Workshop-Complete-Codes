'''
Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
Example:
        Input - grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
        Output - 8
        Explanation - There are 8 negatives number in the matrix.
        
        Input - grid = [[3,2],[1,0]]
        Output - 0
        
Constraints:
        Time complexity - O(m*logn)
        Space complexity - O(1)
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 100
        -100 <= grid[i][j] <= 100
'''

class Solution:
    def __init__(self):
        pass
    def countNegatives(self, grid):
        def binSearch(arr, n):
            if n == 1:
                return (arr[0] >= 0)
            
            l, r = 0, n - 1
            while l <= r:
                m = (l + r)//2
                if arr[m] >= 0:
                    l = m + 1
                else:
                    if m > 0 and arr[m - 1] < 0:
                        r = m - 1
                    elif arr[m] < 0:
                        return m
            return n
            
        count, n = 0, len(grid[0])
        for i in grid:
            m = binSearch(i, n)
            count += (n - m)
        
        return count
        
if __name__ == "__main__":
    temp = input()
    temp = temp[1:-1].split('],')
    n = len(temp)
    
    while n > 0:
        if n != 1:
            temp.append(temp.pop(0) + ']')
        n -= 1
    temp.append(temp.pop(0))
    
    grid = [[int(j.strip()) for j in i.strip()[1:-1].split(',')] for i in temp]
    sol = Solution()
    print(sol.countNegatives(grid))
    
