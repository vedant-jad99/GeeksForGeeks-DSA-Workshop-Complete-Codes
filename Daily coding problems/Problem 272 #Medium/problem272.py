class Solution:
    def noOfWays(self, M, N, X):
        # code here
        if X > M * N:
            return 0
            
        ways = [[0 for _ in range(M * N + 1)] for _ in range(N + 1)]
        
        for i in range(1, M + 1):
            ways[1][i] = 1
        
        for i in range(2, N + 1):
            for j in range(1, X + 1):
                for k in range(1, M + 1):
                    if j - k <= 0:
                        continue
                    ways[i][j] += ways[i - 1][j - k]
                 
        return ways[N][X]
