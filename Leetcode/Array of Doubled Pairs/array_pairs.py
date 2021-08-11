"""
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3877/
"""

class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        if len(arr)%2 == 1:
            return False
        
        arr = sorted(arr)
        counts = {}
        for i in arr:
            if i in counts:
                counts[i] += 1
            else:
                counts[i] = 1
                
        for i in arr:
            if counts[i] != 0 and 2 * i in counts:
                if counts[2 * i] == 0:
                    continue
                counts[i] -= 1
                counts[2 * i] -= 1
            # print(counts)
                
        for value in counts.values():
            if value > 0:
                return False
                            
        return True
