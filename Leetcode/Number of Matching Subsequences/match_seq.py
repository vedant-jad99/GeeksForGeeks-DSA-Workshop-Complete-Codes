"""
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining 
characters.
For example, "ace" is a subsequence of "abcde".
Example:
        Input - s = "abcde", words = ["a","bb","acd","ace"]
        Output - 3
        Explanation - There are three strings in words that are a subsequence of s: "a", "acd", "ace".

        Input - s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
        Output - 2
        
Constraints:
        Time complexity - O(s1 + n*max(s2))
        Space complexity - O(s1)
        1 <= s.length <= 5 * 104
        1 <= words.length <= 5000
        1 <= words[i].length <= 50
        s and words[i] consist of only lowercase English letters.
"""

class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        def createDict(s1):
            n, count = len(s1), 0
            dictionary, order = {}, []
            
            for index, i in enumerate(s1):
                if i in dictionary:
                    dictionary[i].append(index)
                else:
                    dictionary[i] = [index]
            return dictionary
            
        def isSubsequence(maps, s2):
            currentPos = -1
            for i in word:
                if i not in maps or maps[i][-1] <= currentPos:
                    return False
                currentPos= next(value for k, value in enumerate(maps[i]) if value > currentPos)
                print(currentPos)
            print()
            return True
            
            
        subsequences = 0
        word_dict = createDict(s)
        for word in words:
            if isSubsequence(word_dict, word):
                subsequences += 1
        
        return subsequences
