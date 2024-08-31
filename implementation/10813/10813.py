n, m = map(int, input().split())
arr = [i for i in range(0, n + 1)]

for i in range(n + 1):
	arr.append(i)

for i in range(m):
	a, b = map(int, input().split())
	arr[a], arr[b] = arr[b], arr[a]

for e in arr[1:]:
	print(e, end = ' ')

