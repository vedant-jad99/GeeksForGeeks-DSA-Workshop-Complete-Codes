'''
There are several cards arranged in a row, and each card has an associated number of points. The points are 
given in the integer array cardPoints.
- In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k 
cards.
- Your score is the sum of the points of the cards you have taken.
- Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
Example:
    Input - cardPoints = [1,2,3,4,5,6,1], k = 3
    Output - 12
    Explanation - After the first step, your score will always be 1. However, choosing the rightmost card first 
                  will maximize your total score.

    Input - cardPoints = [1,79,80,1,1,1,200,1], k = 4
    Output - 281
    Explanation - 1 + 200 + 1 + 79 = 281

Constraints:
        Time complexity - O(n)
        Space complexity - O(1)
        1 <= cardPoints.length <= 10^5
        1 <= cardPoints[i] <= 10^4
        1 <= k <= cardPoints.length

Topic Tags - Dynamic Programming
'''

def maxScore(cardPoints, k):
    if k == 1:
        return max(cardPoints[0], cardPoints[-1])
    if k == len(cardPoints):
        return sum(cardPoints)
    
    start, n, total_points = 0, len(cardPoints), sum(cardPoints)
    curr = sum(cardPoints[start:start + n - k])
    answer = total_points - curr
    for _ in range(k):
        curr = curr - cardPoints[start] + cardPoints[n - k + start]
        answer = max(answer, total_points - curr)
        start += 1 
    
    return answer

if __name__ == '__main__':
    arr = input()
    k = int(input())
    arr = [int(i) for i in arr[1:-1].split(',')]
    print(maxScore(arr, k))
