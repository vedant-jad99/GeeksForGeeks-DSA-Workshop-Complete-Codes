"""
Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the array.
Return the minimum size of the set so that at least half of the integers of the array are removed.
Example:
        Input - arr = [3,3,3,3,5,5,5,2,2,7]
        Output - 2
        Explanation - Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
                    Possible sets of size 2 are {3,5},{3,2},{5,2}. Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has size 
                    greater than half of the size of the old array.
                    
        Input - arr = [7,7,7,7,7,7]
        Output - 1
        
Constraints:
        Time complexity - O(max(k*logk, n))
        Space complexity - O(k)        
        1 <= arr.length <= 10^5
        arr.length is even.
        1 <= arr[i] <= 10^5
        
Approach - Greedy Solution using heap.
"""

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        hashmap, count, n = {}, 0, len(arr)
        for i in arr:
            try:
                hashmap[i] += 1
            except:
                hashmap[i] = 1
                count += 1
        
        if count == n:
            return count//2
        
        heap = [-i for i in hashmap.values()]
        heapify(heap)
        
        count = 0
        n_copy = n//2
        while n_copy < n:
            n += heappop(heap)
            count += 1
        return count
