'''
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the 
same.
In one step, you can delete exactly one character in either string.
Example:
        Input - word1 = 'sea', word2 = 'eat'
        Output - 2
        Explanation - You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

        Input - word1 = 'leetcode', word2 = 'etco'
        Output - 4

Constraints:
        Time complexity - O(mn)
        Space complexity - O(mn)
        1 <= word1.length, word2.length <= 500
        word1 and word2 consist of only lowercase English letters.
'''

from numpy import zeros

def minDistance(word1, word2):
    m, n = len(word1), len(word2)
    arr = zeros((m + 1, n + 1))

    #Calculating longest common subsequence
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if word1[i - 1] == word2[j - 1]:
                arr[i][j] = arr[i - 1][j - 1] + 1
            else:
                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j])

    #Total number of changes (insertion and deletion)
    return m + n - 2 * int(arr[m][n])

if __name__ == '__main__':
    s1 = input()
    words = s1.split(' ')
    print("\n" + str(minDistance(words[0], words[1])))