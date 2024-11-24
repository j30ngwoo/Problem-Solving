import sys
input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n):
	arr.append(list(map(int, input().split())))
arr.sort(key = lambda x: (x[1], x[0]))
for e in arr:
	print(e[0], e[1])