m, n, k = map(int, input().split())
signal = []
for _ in range(m):
	signal.append(input())
result = [["X" for j in range(n * k)] for i in range(m * k)]

for y in range(m):
	for x in range(n):
		if signal[y][x] == '.':
			for result_y in range(y * k, (y + 1) * k):
				for result_x in range(x * k, (x + 1) * k):
					result[result_y][result_x] = '.'

for y in range(m * k):
	for x in range(n * k):
		print(result[y][x], end='')
	print()