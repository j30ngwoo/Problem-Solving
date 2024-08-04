n, m = map(int, input().split())
profit = [[0 for _ in range(m)]	]
counts = [[] * n]
for i in range(n):
	profit.append(list(map(int, input().split()))[1:])

dp = [0] * (n + 1)
for firm in range(m):
	print(dp)
	for money in range(1, n + 1):
		m = 0
		temp = dp
		for accum_money in range(money + 1):
			now_money = money - accum_money
			if m < dp[accum_money] + profit[now_money][firm]:
				m = dp[accum_money] + profit[now_money][firm]
		temp[money] = m
	dp = temp
print(max(dp))