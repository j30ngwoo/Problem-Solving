import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
asc = [1] * n
desc = [1] * n

for i in range(1, n):
	if arr[i - 1] <= arr[i]:
		asc[i] = asc[i - 1] + 1
	if arr[i - 1] >= arr[i]:
		desc[i] = desc[i - 1] + 1

print(max(max(asc), max(desc)))