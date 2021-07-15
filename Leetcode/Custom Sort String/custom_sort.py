"""
Link to the question - https://leetcode.com/explore/featured/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3813/
"""

class Solution:
    def customSortString(self, order: str, string: str) -> str:
        letters = Counter(string)
        output = ""
        for i in order:
            if i not in letters:
                continue
            output += i * letters[i]
                
            del letters[i]
            
        for key, val in sorted(letters.items()):
            output += key * val
        
        return output
