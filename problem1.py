def find_pair(arr, target):
    pairs = {}
    for i in arr:
        try:
            pairs[target - i]
            return True
        except:
            pairs[i] = 0
    return False

arr = input().split()
arr = [int(ele) for ele in arr]
k = int(input())
print(find_pair(arr, k))
