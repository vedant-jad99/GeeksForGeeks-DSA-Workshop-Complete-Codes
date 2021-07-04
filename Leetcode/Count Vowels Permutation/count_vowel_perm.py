"""
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
    Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
    Each vowel 'a' may only be followed by an 'e'.
    Each vowel 'e' may only be followed by an 'a' or an 'i'.
    Each vowel 'i' may not be followed by another 'i'.
    Each vowel 'o' may only be followed by an 'i' or a 'u'.
    Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.
Example:
        Input - n = 1
        Output - 5
        Explanation - All possible strings are: "a", "e", "i" , "o" and "u".
        
        Input - n = 2
        Output - 10
        
Constraints:
        Time complexity - O(N) [ o(5N) ]
        Space complexity - O(N) [ o(5N) ]
        1 <= n <= 2 * 10^4
        
Hints:
      Use dynamic programming.
      Let dp[i][j] be the number of strings of length i that ends with the j-th vowel.
      Deduce the recurrence from the given relations between vowels.
"""

import numpy as np
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        dp = np.zeros((n, 5), dtype="Int64")
        rules = {0: [1], 1: [0, 2], 2: [0, 1, 3, 4], 3: [2, 4], 4: [0]}
        
        for i in range(n):
            for j in range(5):
                if i == 0:
                    dp[i][j] = 1
                    continue
                for k in rules[j]:
                    dp[i][k] = (dp[i - 1][j]%1000000007 + dp[i][k]%1000000007)%1000000007
        
        return sum(dp[n - 1])%1000000007
