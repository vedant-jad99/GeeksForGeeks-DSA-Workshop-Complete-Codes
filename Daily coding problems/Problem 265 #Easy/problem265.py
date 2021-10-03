class Solution:
    def candy(self, ratings: List[int]) -> int:
        ans = [1 for _ in ratings]
        
        l = len(ratings)
        for i in range(1, l):
            if ratings[i] > ratings[i - 1]:
                ans[i] = ans[i - 1] + 1
        
        for i in range(l - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                ans[i] = max(ans[i], ans[i + 1] + 1)
        
        return ans
