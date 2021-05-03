'''
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an 
array of the non-overlapping intervals that cover all the intervals in the input.
Example:
        Input - intervals = [[1,3],[2,6],[8,10],[15,18]]
        Output - [[1,6],[8,10],[15,18]]
        Explanation - Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

        Input - intervals = [[1,4],[4,5]]
        Output - [[1,5]]
        Explanation - Intervals [1,4] and [4,5] are considered overlapping.

Constraints:
        Time Complexity - O(N*logN)
        Space Complexity - O(N)
        1 <= intervals.length <= 10^4
        intervals[i].length == 2
        0 <= starti <= endi <= 10^4
'''

def merge(intervals):
    intervals.sort()
    merge = []
    index = 0
    for i in intervals:
        if len(merge) == 0:
            merge.append(i)
        else:
            if i[0] >= merge[index][0] and i[0] <= merge[index][1]:
                merge.append([merge[index][0], max(merge[index][1], i[1])])
                merge.pop(index)
            else:
                merge.append(i)
                index += 1
                
    return merge

if __name__ == '__main__':
    string = input()[1:-1]
    lists = string.split(']')

    intervals = []
    for interval in lists[:-1]:
        if interval[0] == ",":
            interval = interval[2:].split(',')
            intervals.append([int(i) for i in interval])
            continue    
        interval = interval[1:].split(',')
        intervals.append([int(i) for i in interval])

    print(merge(intervals))