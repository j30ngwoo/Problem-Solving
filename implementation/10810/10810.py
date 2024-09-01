import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [0] * (n + 1)

for _ in range(m):
	i, j, k = map(int, input().split())
	for index in range(i, j + 1):
		arr[index] = k

for e in arr[1:]:
	print(e, end=' ')