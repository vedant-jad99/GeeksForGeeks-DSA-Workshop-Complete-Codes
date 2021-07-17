"""
Link to the question - https://leetcode.com/explore/featured/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3817/
"""

class Solution:
    def threeEqualParts(self, arr: List[int]) -> List[int]:
        """
        --------------------------------------------------------------------------
        Approach 1: 
        Dividing the array in equal parts and comparing each part, continuously.
        
        Time complexity - O(n^2). 
        Test cases passed - 108/118
        --------------------------------------------------------------------------
        
        if len(arr) < 3:
            return [-1, -1]
        
        arr = [str(i) for i in arr]
        string = ''.join(arr)
        
        for i in range(len(arr) - 2):
            for j in range(i + 1, len(arr) - 1):
                if int(string[:i + 1]) == int(string[i + 1:j + 1]):
                    if int(string[i + 1:j + 1]) == int(string[j + 1:]):
                        return [i, j + 1]
                    
        return [-1, -1]
        """     
        
        """
        ----------------------------------------------------------------------------
        Approach 2:
        To divide in 3 parts, every part must have equal number of ones.
        
        Time complexity - O(n)
        Test cases passed - All
        """
        n_ones = sum(arr)
        if n_ones == 0:
            return [0, len(arr) - 1]
        elif n_ones%3 != 0:
            return [-1, -1]
        
        part = n_ones/3
        ones = 0
        
        possible = []
        for i, e in enumerate(arr):
            if e == 1:
                ones += e
                if ones in {1, part + 1, 2 * part + 1}:
                    possible.append(i)
                if ones in {part, 2*part, 3*part}:
                    possible.append(i)
                
        p1, p2, q1, q2, r1, r2 = possible
        
        if not(arr[p1:p2] == arr[q1:q2] == arr[r1:r2]):
            return [-1, -1]
        
        x = q1 - p2 - 1
        y = r1 - q2 - 1
        z = len(arr) - r2 - 1
        
        if x < z or y < z:
            return [-1, -1]
        
        return [p2 + z, q2 + z + 1]
