import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
wines = [int(input()) for _ in range(n)]
dp = [[0, 0, 0] for _ in range(n + 1)]

for i in range(n):
    dp[i][0] = max(dp[i - 1])
    dp[i][1] = dp[i - 1][0] + wines[i]
    dp[i][2] = dp[i - 1][1] + wines[i]

print(max(dp[n - 1]))