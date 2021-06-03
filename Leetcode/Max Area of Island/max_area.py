"""
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.
Example:
        Input - grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
        Output - 6
        Explanation - Grid (given below). We can see that the max area of 1s is 6
        0 0 1 0 0 0 0 1 0 0 0 0 0
        0 0 0 0 0 0 0 1 1 1 0 0 0
        0 1 1 0 1 0 0 0 0 0 0 0 0
        0 1 0 0 1 1 0 0 1 0 1 0 0
        0 1 0 0 1 1 0 0 1 1 1 0 0
        0 0 0 0 0 0 0 0 0 0 1 0 0
        0 0 0 0 0 0 0 1 1 1 0 0 0
        0 0 0 0 0 0 0 1 1 0 0 0 0
        
        Input - grid = [[0,0,0,0,0,0,0,0]]
        Output - 0
        
Constraints:
        Time complexity - O(m*n)
        Space complexity - O(1) [Recursion stack space - O(m*n)]
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 50
        grid[i][j] is either 0 or 1.
"""
class Solution:
    def __init__(self):
        pass
    def maxAreaOfIsland(self, grid):
        def check(grid, i, j, m, n):
            if i < 0 or j < 0 or i >= m or j >= n:
                return 0
            elif grid[i][j] == "0":
                return 0
            elif grid[i][j] == "1":
                grid[i][j] = "0"
                return check(grid, i - 1, j, m, n) + check(grid, i, j - 1, m, n) + check(grid, i + 1, j, m, n) + check(grid, i, j + 1, m, n) + 1
                
        m, n, area = len(grid), len(grid[0]), 0
        for i in range(m):
            for j in range(n):
                count = check(grid, i, j, m, n)
                area = max(count, area)
                
        return area
        
if __name__ == "__main__":
    grid = []
    temp_grid = input()
    temp_grid = temp_grid[1:-1].split('],')
    n = len(temp_grid)
    temp_grid = [i + ']' if count < n - 1 else i for count, i in enumerate(temp_grid)]
    
    for i in temp_grid:
        ele = i[1:-1].split(',')
        grid.append(ele)
        
    sol = Solution()
    print(sol.maxAreaOfIsland(grid))
    
    
    
