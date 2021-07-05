"""
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
You are given an m x n matrix mat and two integers r and c representing the row number and column number of the wanted reshaped matrix.
The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
Example:
        Input - mat = [[1,2],[3,4]], r = 1, c = 4
        Output - [[1,2,3,4]]

        Input - mat = [[1,2],[3,4]], r = 2, c = 4
        Output - [[1,2],[3,4]]

Constraints:
        Time complexity - O(r*c)
        Space complexity - O(r*c)
        m == mat.length
        n == mat[i].length
        1 <= m, n <= 100
        -1000 <= mat[i][j] <= 1000
        1 <= r, c <= 300
"""

from numpy import zeros
class Solution:
    def matrixReshape(self, mat, r, c):
        m, n = len(mat), len(mat[0])
        if r * c != m * n:
            return mat
        
        ret_mat = zeros((r, c), dtype="int64")
        c_r, c_c = 0, 0
        
        for i in mat:
            for j in i:
                ret_mat[c_r][c_c] = j
                c_c += 1
                if c_c == c:
                    c_c = 0
                    c_r += 1
        
        return ret_mat
