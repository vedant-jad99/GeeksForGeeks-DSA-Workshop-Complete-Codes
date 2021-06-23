"""
Given a dictionary of words and an M x N board where every cell has one character. Find all possible different words from the dictionary that can be formed by a sequence of 
adjacent characters on the board. We can move to any of 8 adjacent characters, but a word should not have multiple instances of the same cell.
Example:
        Input - N = 1, dictionary = {"CAT"}, R = 3, C = 3, board = {{C,A,P},{A,N,D},{T,I,E}}
        Output - CAT
        Explanation: 
        |C| A P
        |A| N D
        |T| I E
        
        Input - N = 4, dictionary = {"GEEKS","FOR","QUIZ","GO"}, R = 3, C = 3, board = {{G,I,Z},{U,E,K},{Q,S,E}}
        Output - GEEKS QUIZ

Constraints:
        Time Complexity - O(4^(N^2))
        Space Complexity - O(N^2)
        1 ≤ N ≤ 15
        1 ≤ R, C ≤ 50
        1 ≤ length of Word ≤ 60
        All words of Dictionary and all characters of board are in uppercase letters from 'A' to 'Z'

PS: Although the title says C++, the solution is in Python, because, well Python is awesome!!! And hella lot easier to code
"""

class Solution:
    def wordBoggle(self,board,dictionary):
        # return list of words(str) found in the board
        def modify_board(board):
            m = len(board[0])
            for ind, i in enumerate(board):
                board[ind] = ['0'] + i + ['0']
        
            board = [['0']*(m + 2)] + board + [['0']*(m + 2)]
            return board
        
        def search_letter(board, letter):
            n, m = len(board), len(board[0])
            points = []
            for i in range(1, n - 1):
                for j in range(1, m - 1):
                    if board[i][j] == letter:
                        points.append((i, j))
            return points
            
        def dfs(word, i, j, board):
            if word == "":
                return True
                
            ans = False
            for x in [-1, 0, 1]:
                for y in [-1, 0, 1]:
                    if x == 0 and y == 0:
                        continue
                    
                    if board[i + x][j + y] == word[0]:
                        board[i + x][j + y] = '0'
                        if dfs(word[1:], i + x, j + y, board):
                            return True
                        
                        board[i + x][j + y] = word[0]
            return ans
            
        
        board = modify_board(board)
        words = set()
        for word in dictionary:
            copy = []
            for i in board:
                copy.append(i.copy())
            points = search_letter(copy, word[0])
            if len(points) is 0:
                continue
            for i, j in points:
                copy[i][j] = "0"
                if dfs(word[1:], i, j, copy):
                    words.add(word)
                copy[i][j] = word[0]
    
        return list(words)
