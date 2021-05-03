'''
There are n different online courses numbered from 1 to n. You are given an array courses where 
courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days 
and must be finished before or on lastDayi.
You will start on the 1st day and you cannot take two or more courses simultaneously.
Return the maximum number of courses that you can take.
Example: 
        Input - courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
        Output - 3
        Explanation - 
        There are totally 4 courses, but you can take 3 courses at most:
        First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
        Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
        Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
        The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.

        Input - courses = [[3,2],[4,3]]
        Output - 0

Constraints -  
        Time Complexity - O(N)
        1 <= courses.length <= 10^4
        1 <= durationi, lastDayi <= 10^4
'''

import heapq

def scheduleCourse(courses):
    if len(courses) == 1:
        return 1
    
    asc_courses = sorted(courses, key=lambda x: x[1])
    a = []
    
    days = 0; total = 0; max_ = 0;
    for course in asc_courses:
        x, y = course[0], course[1]
        if x > y:
            continue
        
        if days + x <= y:
            days += x
            total += 1   
            heapq.heappush(a, -x)
            heapq.heapify(a)
        else:
            days += x
            heapq.heappush(a, -x)
            days += heapq.heappop(a)                
            
    return total

if __name__ == '__main__':
    n = int(input())
    courses = [[int(input()) for i in range(2)] for i in range(n)]
    print(scheduleCourse(courses))
