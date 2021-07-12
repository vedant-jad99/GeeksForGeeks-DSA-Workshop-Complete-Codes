"""
Link to the question - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3809/
"""

class Solution:
    def numDecodings(self, s: str) -> int:
        if s == '0':
            return 0
        if s == '*':
            return 9
        if len(s) < 2:
            return 1
        
        l = len(s)
        dp = [0 for _ in s]
        if s[-1] != '*' and s[-1] != '0':
            dp[-1] = 1
        elif s[-1] == '*':
            dp[-1] = 9
        
        
        MOD = 10**9 + 7
        for i in range(l - 2, -1, -1):
            if s[i] == '0':
                continue
            if s[i] == '*':
                if s[i + 1] != '*' and s[i + 1] < '7':
                    try:
                        dp[i] = (9 * dp[i + 1] + 2 * dp[i + 2])%MOD
                    except:
                        dp[i] = 9 * dp[i + 1] + 2
                elif s[i + 1] != '*' and s[i + 1] > '6':
                    try:
                        dp[i] = (9 * dp[i + 1] + dp[i + 2])%MOD
                    except:
                        dp[i] = 9 * dp[i + 1] + 1
                else:
                    try:
                        dp[i] = (9 * dp[i + 1] + 15 * dp[i + 2])%MOD
                    except:
                        dp[i] = 9 * dp[i + 1] + 15
            else:
                if s[i + 1] == '*' and s[i] > '2':
                    dp[i] = dp[i + 1]
                elif s[i + 1] == '*' and s[i] == '2':
                    try:
                        dp[i] = (dp[i + 1] + 6 * dp[i + 2])%MOD
                    except:
                        dp[i] = dp[i + 1] + 6
                elif s[i + 1] == "*" and s[i] == '1':
                    try:
                        dp[i] = (dp[i + 1] + 9 * dp[i + 2])%MOD
                    except:
                        dp[i] = dp[i + 1] + 9
                else:
                    if int(s[i] + s[i + 1]) <= 26:
                        try:
                            dp[i] = (dp[i + 1] + dp[i + 2])%MOD
                        except:
                            dp[i] = dp[i + 1] + 1
                    else:
                        dp[i] = dp[i + 1]
        
        # print(dp)
        return dp[0]
