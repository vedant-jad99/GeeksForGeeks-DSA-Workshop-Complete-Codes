"""
Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts where horizontalCuts[i] is the distance from the top of the 
rectangular cake to the ith horizontal cut and similarly, verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can 
be a huge number, return this modulo 10^9 + 7.
Example:
        Input - h = 5, w = 4, h_cuts = [1,2,4], v_cuts = [1,3]
        Output - 4 
        Explanation - After you cut the cake, will be between cuts 2, 4 and 1, 3.
        
        Input - h = 5, w = 4, h_cuts = [3,1], v_cuts = [1]
        Output - 6
        
Constraints:
        Time complexity - O(nlogn)
        Space complexity - O(1)
        2 <= h, w <= 10^9
        1 <= horizontalCuts.length < min(h, 10^5)
        1 <= verticalCuts.length < min(w, 10^5)
        1 <= horizontalCuts[i] < h
        1 <= verticalCuts[i] < w
        It is guaranteed that all elements in horizontalCuts are distinct.
        It is guaranteed that all elements in verticalCuts are distinct.
"""

class Solution:
    def __init__(self):
        pass
    def maxArea(self, h, w, h_cuts, v_cuts):
        h_cuts = [0] + h_cuts + [h]
        v_cuts = [0] + v_cuts + [w]
        
        h_cuts.sort()
        v_cuts.sort()
        
        h_max, v_max = -1, -1
        for i in range(1, len(h_cuts)):
            h_max = max(h_max, h_cuts[i] - h_cuts[i - 1])
        for i in range(1, len(v_cuts)):
            v_max = max(v_max, v_cuts[i] - v_cuts[i - 1])
        
        return (h_max * v_max)%1000000007
    
if __name__ == "__main__":
    [h, w] = input().split(',')
    h, w = int(h.strip()), int(w.strip())
    
    h_cuts = input()[1:-1].split(',')
    h_cuts = [int(i.strip()) for i in h_cuts]
    
    v_cuts = input()[1:-1].split(',')
    v_cuts = [int(i.strip()) for i in v_cuts]
    
    sol = Solution()
    print(sol.maxArea(h, w, h_cuts, v_cuts))
