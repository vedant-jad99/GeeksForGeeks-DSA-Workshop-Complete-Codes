"""
An n-bit gray code sequence is a sequence of 2n integers where:
  Every integer is in the inclusive range [0, 2n - 1],
  The first integer is 0,
  An integer appears no more than once in the sequence,
  The binary representation of every pair of adjacent integers differs by exactly one bit, and
  The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.
Example:
        Input - n = 2
        Output - [0,1,3,2]
        Explanation - [00,01,11,10]
        
        Input - n = 1
        Output - [0,1]
        
Constraints:
        Time complexity - O(2^n)
        Space complexity - O(n) [recursion stack], O(2^n) Output space
        1 <= n <= 16
"""

class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n == 1:
            return [0, 1]
        
        res = []
        ans = self.grayCode(n - 1)
        mask = 1<<(n - 1)
        for i in ans[::-1]:
            res.append(mask|i)
            
        return ans + res
