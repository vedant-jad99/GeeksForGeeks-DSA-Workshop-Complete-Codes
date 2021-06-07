"""
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
Example:
        Input - matrix = [[1,1,1],[1,0,1],[1,1,1]]
        Output - [[1,0,1],[0,0,0],[1,0,1]]
        Example - Matrix:
        1 1 1    1 0 1
        1 0 1 =  0 0 0
        1 1 1    1 0 1
        
        Input - matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
        Output - [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
        
Constraints:
        Time complexity - O(m*n)
        Space complexity - O(1)
        m == matrix.length
        n == matrix[0].length
        1 <= m, n <= 200
        -2^31 <= matrix[i][j] <= 2^31 - 1
"""

class Solution:
    def __init__(self):
        pass
    def setZeroes(self, matrix):
        m, n = len(matrix), len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    matrix[i][j] = 'x'
            
        for i in matrix:
            if 'x' in i:
                for j in range(n):
                    if i[j] != 'x':
                        i[j] = 0
            
            for j in range(n):
                if i[j] == 'x':
                    for k in range(m):
                        if matrix[k][j] != 'x':
                            matrix[k][j] = 0
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 'x': matrix[i][j] = 0
    
    '''
    Better approach - O(n^2). In this approach, we mark the first(0th) row and column as flags. If we encounter a zero in matrix at [i,j] index, we set [i,0] and [j,0] as 0 indicating
    that the corresponding row and column need to be set zero.
    
    def setZeroes(self, matrix: List[List[int]]) -> None:
        is_col = False
        R = len(matrix)
        C = len(matrix[0])
        for i in range(R):
            # Since first cell for both first row and first column is the same i.e. matrix[0][0]
            # We can use an additional variable for either the first row/column.
            # For this solution we are using an additional variable for the first column
            # and using matrix[0][0] for the first row.
            if matrix[i][0] == 0:
                is_col = True
            for j in range(1, C):
                # If an element is zero, we set the first element of the corresponding row and column to 0
                if matrix[i][j]  == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0

        # Iterate over the array once again and using the first row and first column, update the elements.
        for i in range(1, R):
            for j in range(1, C):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j] = 0

        # See if the first row needs to be set to zero as well
        if matrix[0][0] == 0:
            for j in range(C):
                matrix[0][j] = 0

        # See if the first column needs to be set to zero as well        
        if is_col:
            for i in range(R):
                matrix[i][0] = 0'''
    
    
if __name__ == "__main__":
    temp = [i for i in input()[1:-1].split('],')]
    for _ in range(len(temp) - 1):
        temp.append(temp[0].strip() + ']')
        temp.pop(0)

    temp.append(temp.pop(0))
    matrix = [[int(i.strip()) for i in j[1:-1].split(',')] for j in temp]]
    sol = Solution()
    
    sol.setZeroes(matrix)
    print(matrix)
