"""
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.
The lock initially starts at '0000', a string representing the state of the 4 wheels.
You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
Example:
        Input - deadends = ["0201","0101","0102","1212","2002"], target = "0202"
        Output - 6
        Explanation - A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
        Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid, because the wheels of the lock become stuck after the display becomes the dead end "0102".

        Input - deadends = ["8888"], target = "0009"
        Output - 1
        Explanation - We can turn the last wheel in reverse to move from "0000" -> "0009".

Constraints:
        Time complexity - O(N*d), N = nodes[strings] (max 10000, all possible strings) and d = 4
        Space complexity - O(8^L), L = level (As queue contains at 8^level number of nodes at each level)
        1 <= deadends.length <= 500
        deadends[i].length == 4
        target.length == 4
        target will not be in the list deadends.
        target and deadends[i] consist of digits only.
"""

next_dict = {'0': '1', '1': '2', '2': '3', '3': '4', '4': '5', '5': '6', '6': '7', '7': '8', '8': '9', '9': '0'}
prev_dict = {'0': '9', '1': '0', '2': '1', '3': '2', '4': '3', '5': '4', '6': '5', '7': '6', '8': '7', '9': '8'}

class Solution:
    def __init__(self):
        pass
    def openLock(self, deadends, target):
        start = "0000"
        if target == start:
            return 0
        if start in deadends:
            return -1
        
        queue = [start]
        dead, level = {i: 1 for i in deadends}, 0
        
        while len(queue) != 0:
            l = len(queue)
            level += 1
            while l > 0:
                el = queue.pop(0)
                dead[el] = 1
                for i in range(4):
                    new1 = el[:i] + next_dict[el[i]] + el[i + 1:]
                    new2 = el[:i] + prev_dict[el[i]] + el[i + 1:]
                    try:
                        if dead[new1] == 1:
                            pass
                    except:
                        dead[new1] = 1
                        queue.append(new1)

                    try:
                        if dead[new2] == 1:
                            pass
                    except:
                        dead[new2] = 1
                        queue.append(new2)

                    if new1 == target or new2 == target:
                        return level
                l -= 1
        return -1

if __name__ == "__main__":
    target = input()
    raw_deadend = input()
    deadends = [i.strip()[1:-1] for i in raw_deadend[1:-1].split(',')]

    sol = Solution()
    print(sol.openLock(deadends, target))
