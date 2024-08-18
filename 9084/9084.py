import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
	dp = [1] + [0] * 10000
	n = int(input())
	coins = list(map(int, input().split()))
	m = int(input())
	for i in range(1, m + 1):
		dp[i] = dp[i] - 1
		for coin in coins:
			if i - coin >= 0:
				dp[i] += 1
	print(dp[:m + 1])
	print(dp[m])