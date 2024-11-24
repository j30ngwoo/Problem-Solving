import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
arr = []

for _ in range(n):
	arr.append(list(map(int, input().split())))

arr.sort()

for e in arr:
	print(e[0], e[1])