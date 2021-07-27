"""
Link to the question - https://leetcode.com/problems/minimum-time-difference/
"""

class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def convertTime(time):
            time = time.split(":")
            mintues = 0
            minutes = int(time[0]) * 60 + int(time[1])
            return minutes           
        
        minimum = 14400
        timePoints = sorted(timePoints)
        for i, _ in enumerate(timePoints[:-1]):
            curr = convertTime(timePoints[i])
            next_t = convertTime(timePoints[i + 1])
            minimum = min(minimum, next_t - curr)
            
        minimum = min(minimum, abs(convertTime(timePoints[-1]) - (1440 + convertTime(timePoints[0]))))
        return minimum
