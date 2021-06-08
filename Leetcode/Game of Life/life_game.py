"""
According to Wikipedia's article: 'The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.'
The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight 
neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. 
Given the current state of the m x n grid board, return the next state.
Example:
        Input - board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
        Output - [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
        Explanation - Board:
        0 1 0    0 0 0
        0 0 1 =  1 0 1
        1 1 1    0 1 1
        0 0 0    0 1 0
        
        Input - board = [[1,1],[1,0]]
        Output - [[1,1],[1,1]]
        
Constraints:
        Time complexity - O(m*n)
        Space complexity - O(m*n)
        m == board.length
        n == board[i].length
        1 <= m, n <= 25
        board[i][j] is 0 or 1.

Note - Follow up:
    1. Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update 
        other cells.
    2. In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the 
        border of the array (i.e., live cells reach the border). How would you address these problems?
        
PS: Too tired to write the driver code, so just pasting the solution. Also, I will follow up solution later.
"""

import numpy as np
class Solution:
    def __init__(self):
        pass
    def gameOfLife(self, board: List[List[int]]) -> None:
        def convolve(board, index1, index2):
            total = 0
            for i in [-1, 0, 1]:
                for j in [-1, 0, 1]:
                    total += board[index1 + i][index2 + j] * 1
            if board[index1][index2] == 1:
                return total - 1
            return total
        
        m, n = len(board), len(board[0])
        next_board = np.pad(board, (1,), 'constant', constant_values=[0])
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                live = convolve(next_board, i, j)
                if live == 3 or (live == 2 and next_board[i][j] == 1):
                    board[i - 1][j - 1] = 1
                else:
                    board[i - 1][j - 1] = 0                
