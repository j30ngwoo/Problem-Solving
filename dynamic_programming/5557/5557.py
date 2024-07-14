n = int(input())
arr = list(map(int, input().split()))
dp = [[0 for _ in range(21)] for _ in range(n - 1)]
dp[0][arr[0]] = 1

for index in range(n - 2):
	for accum_num in range(0, 20 + 1):
		added = accum_num + arr[index + 1]
		subtracted = accum_num - arr[index + 1]
		if 0 <= added <= 20:
			dp[index + 1][added] += dp[index][accum_num]
		if 0 <= subtracted <= 20:
			dp[index + 1][subtracted] += dp[index][accum_num]

print(dp[n - 2][arr[-1]])