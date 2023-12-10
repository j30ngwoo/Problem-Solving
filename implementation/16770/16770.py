n = int(input())
arr = [0] * 1001
for _ in range(n):
	s, t, b = map(int, input().split())
	for i in range(s, t + 1):
		arr[i] += b

print(max(arr))
