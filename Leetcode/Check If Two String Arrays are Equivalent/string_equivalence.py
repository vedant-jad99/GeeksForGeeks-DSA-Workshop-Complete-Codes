"""
Given two string arrays word1 and word2, return true if the two arrays represent the same string,
and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string.
Ex. Input - word1 = ["ab", "c"], word2 = ["a", "bc"]
    Output - true
    Explanation - 
        word1 represents string "ab" + "c" -> "abc"
        word2 represents string "a" + "bc" -> "abc"
        The strings are the same, so return true.

    Input - word1 = ["a", "cb"], word2 = ["ab", "c"]
    Output - false

Constraints - 
    1 <= word1.length, word2.length <= 103
    1 <= word1[i].length, word2[i].length <= 103
    1 <= sum(word1[i].length), sum(word2[i].length) <= 103
    word1[i] and word2[i] consist of lowercase letters.
"""

def array_strings_are_equal(word1, word2):
    string1, string2 = "", ""
    for i in word1:
        string1 += i
    for i in word2:
        string2 += i
    
    if string1 == string2:
        return True
    return False


word1, word2 = [], []
n = input()
n = n.split()
for i in range(int(n[0])):
    word1.append(input())
for i in range(int(n[1])):
    word2.append(input())

print(array_strings_are_equal(word1, word2))
