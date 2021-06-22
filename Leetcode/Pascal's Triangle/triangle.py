"""
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.
Example:
        Input - 5
        Output - [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
        Explanation - 
                1
               1 1
              1 2 1
             1 3 3 1
            1 4 6 4 1
            
        Input - 1
        Output - [[1]]
        
Constraints:
        Time complexity - O(n^2)
        Space complexity - O(n)
        1 <= numRows <= 30
"""

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        if numRows == 2:
            return [[1], [1, 1]]
        
        answer = []
        answer += self.generate(numRows - 1)
        
        last, nth = answer[-1], []
        for i, _ in enumerate(last[:-1]):
            nth.append(last[i] + last[i + 1])
        
        nth = [1] + nth + [1]
        answer.append(nth)
        
        return answer
      
if __name__ == "__main__":
    numRows = int(input)
    sol = Solution()
    ans = sol.generate(numRows)
    print(ans)
