"""
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
Example:
        Input - s = "abbaca"
        Output - "ca"
        Explanation - For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.
                      The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
                      
        Input - s = "azxxzy"
        Output - "ay"
        
Constraints:
        Time complexity - O(s)
        Space complexity - O(s)
        1 <= s.length <= 105
        s consists of lowercase English letters.
"""

class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []
        for i in s:
            if stack == [] or stack[-1] != i:
                stack.append(i)
            else:
                stack.pop()
                
        return "".join(stack)
    
if __name__ == "__main__":
    s = input()
    sol = Solution()
    print(sol.removeDuplicates(s[1:-1]))    
