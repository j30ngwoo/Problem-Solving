n, m = map(int, input().split())
profit = [[0] * m]
for i in range(n):
	profit.append(list(map(int, input().split()))[1:])

dp = [0] * (n + 1)
for firm in range(m):
	print(dp)
	for money in range(1, n + 1):
		l = []
		temp = dp
		for first in range(money + 1):
			second = money - first
			l.append(dp[first] + profit[second][firm])
		temp[money] = max(l)
	dp = temp
print(max(dp))