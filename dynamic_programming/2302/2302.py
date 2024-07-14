n = int(input())
m = int(input())
vips = [int(input()) for _ in range(m)]

dp = [1, 1] + [0] * (n - 1)
for i in range(2, n + 1):
    dp[i] = dp[i - 1] + dp[i - 2]

result = 1
previous_vip = 0
for vip in vips:
    l = vip - previous_vip - 1
    result *= dp[l]
    previous_vip = vip
result *= dp[n - previous_vip]

print(result)
