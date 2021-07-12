"""
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
Example:
        Input - s = "add", t = "egg"
        Output - true
        Explanation - 'e' maps to 'a' and 'd' maps to 'g'
        
        Input - s = "foo", t = "bar"
        Output - false
        
Constrains:
        Time complexity - O(n)
        Space complexity - O(1) [Since size of ASCII characters is fixed]
        1 <= s.length <= 5 * 104
        t.length == s.length
        s and t consist of any valid ascii character.
"""

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapper1 = {}
        mapper2 = {}
        for i, j in zip(s, t):
            if (i not in mapper1) and (j not in mapper2):
                mapper1[i] = j
                mapper2[j] = i
            else:
                try:
                    if mapper1[i] != j and mapper2[j] != i:
                        return False
                except:
                    return False
        return True

