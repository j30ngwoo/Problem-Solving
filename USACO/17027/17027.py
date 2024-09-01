import sys
input = lambda: sys.stdin.readline().strip()

def cnt(pos):
	count = 0
	for a, b, g in arr:
		if pos == a:
			pos = b
		elif pos == b:
			pos = a
		if pos == g:
			count += 1
	return count

n = int(input())
arr = []
for _ in range(n):
	arr.append(list(map(int, input().split())))
print(max(cnt(1), cnt(2), cnt(3)))