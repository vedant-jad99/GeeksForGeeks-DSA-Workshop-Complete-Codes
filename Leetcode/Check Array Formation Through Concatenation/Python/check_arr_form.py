'''
You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers 
in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. 
However, you are not allowed to reorder the integers in each array pieces[i].
Return true if it is possible to form the array arr from pieces. Otherwise, return false.
Ex. Input - arr : [91,4,64,78], pieces : [[78],[4,64],[91]]
    Output - true
    Explanation - Concatenate [91] then [4,64] then [78]
    Input - arr : [49,18,16], pieces : [[16,18,49]]
    Output - false
    Explanation - Even though the numbers match, we cannot reorder pieces[0].
    
Constraints - 
    1 <= pieces.length <= arr.length <= 100
    sum(pieces[i].length) == arr.length
    1 <= pieces[i].length <= arr.length
    1 <= arr[i], pieces[i][j] <= 100

Solution Complexity - 
    Time : O(m + n); m = pieces.length, n = arr.length
    Space : O(m)
'''

def canFormArray(arr, pieces):
        indexing = {}
        for i in pieces:
            indexing[i[0]] = i
            
        i = 0
        while i < len(arr):
            try:
                tmp = indexing[arr[i]]
                for ele in tmp:
                    if ele == arr[i]:
                        i += 1
                    else:
                        return False
            except KeyError:
                return False
            
        return True

if __name__ == '__main__':
    size = input().split()
    arr = input().split()
    pieces = []

    for _ in range(int(size[1])):
        pieces.append(input().split())

    print(canFormArray(arr, pieces))
