import sys
input = sys.stdin.readline

def is_exist(x):
	left = 0
	right = m - 1
	while left <= right:
		mid = (left + right) // 2
		if b[mid] == x:
			return True
		elif b[mid] < x:
			left = mid + 1
		else:
			right = mid - 1
	return False

while True:
	n, m = map(int, input().split())
	if n == 0 and m == 0:
		break
	a = []
	b = []
	for _ in range(n):
		a.append(int(input()))
	for _ in range(m):
		b.append(int(input()))

	count = 0
	for t in a:
		if is_exist(t):
			count += 1
	print(count)