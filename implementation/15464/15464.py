n = int(input())
shuffles = list(map(int, input().split()))
temp = input().split()
arr = [''] * (n + 1)

for _ in range(3):
	for i in range(n):
		arr[i] = temp[shuffles[i] - 1]
	temp = arr.copy()

for id in arr:
	print(id)