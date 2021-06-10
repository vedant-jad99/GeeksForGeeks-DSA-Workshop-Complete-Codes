"""
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
You may return the answer in any order.
Example:
        Input - n = 4, k = 2
        Output - [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
        Explanation - There are total 5C2 combinations.

        Input - n = 1, k = 1
        Output - [[1]]

Constraints:
        Time complexity - O(N!/(k!)(N  -k)!)
        Space complexity - Same
        1 <= n <= 20
        1 <= k <= n
"""
import sys

class Solution:
    def combine(self, n, k):
        def getCombinations(n, k, comb, index):
            if len(comb) == k:
                combinations.append(comb[:])
                return

            for i in range(index, n + 1):
                comb.append(i)
                getCombinations(n, k, comb, i + 1)
                comb.pop()
            return

        combinations = []
        getCombinations(n, k, [], 1)
        return combinations

if __name__ == "__main__":
    args = sys.argv
    n, k = int(args[1]), int(args[2])

    sol = Solution()
    combs = sol.combine(n, k)
    print(combs)
