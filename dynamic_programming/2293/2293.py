n, k = map(int, input().split())
value_cases = [0] * (k + 1)
value_cases[0] = 1
coins = []
for _ in range(n):
	coins.append(int(input()))

#coins.sort(reverse=True)

for coin in coins:
	for value in range(1, k + 1):
		if value - coin >= 0:
			value_cases[value] += value_cases[value - coin]
	#print(value_cases)


print(value_cases[k])