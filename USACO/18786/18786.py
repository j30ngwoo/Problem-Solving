import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
coords = []
for _ in range(n):
	coords.append(list(map(int, input().split())))

max_ = 0
for coord in coords:
	for a in coords:
		for b in coords:
			if coord[0] == a[0] and coord[1] == b[1]:
				max_ = max(max_, abs((coord[1] - a[1]) * (coord[0] - b[0])))
print(max_)