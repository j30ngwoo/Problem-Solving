import sys
input = lambda: sys.stdin.readline().strip()

t = int(input())
arr = [[] for _ in range(10)]

for i in range(1, 10):
	temp = i
	while not arr[i] or temp != arr[i][0]:
		arr[i].append(temp)
		temp *= i
		temp %= 10

for _ in range(t):
	a, b = map(int, input().split())
	if a % 10 == 0:
		print(10)
	else:
		a %= 10
		print(arr[a][(b - 1) % len(arr[a])])