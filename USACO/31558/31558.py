import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
	n = int(input())
	arr = list(map(int, input().split())) + [-1]
	result = set()

	for i in range(n - 1):
		if arr[i] == arr[i + 1] or arr[i] == arr[i + 2]:
			result.add(arr[i])

	result = sorted(list(result))
	if len(result) == 0:
		print(-1)
	else:
		for e in result:
			print(e, end=' ')
		print()