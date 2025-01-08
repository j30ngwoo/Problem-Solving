n, m = map(int, input().split())
firms = [[0 for _ in range(m + 1)]] + [list(map(int, input().split())) for _ in range(n)]
dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]
traceback = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

for v in range(1, n + 1):
    for i in range(1, m + 1):
        for firm_v in range(v + 1):
            value = firms[firm_v][i] + dp[v - firm_v][i - 1]
            if dp[v][i] < value:
                dp[v][i] = value
                traceback[v][i] = firm_v

remain = n
route = []
for i in range(m, 0, -1):
    route.append(traceback[remain][i])
    remain -= route[-1]

print(dp[n][m])
print(' '.join(map(str, route[::-1])))