import sys
input = lambda: sys.stdin.readline().rstrip()
from copy import deepcopy

def main():
	n, m = map(int, input().split())
	k = int(input())
	grid = [list(map(int, input().split())) for _ in range(n)]

	grid_down = deepcopy(grid)
	grid_right = deepcopy(grid)

	for y in range(n):
		for x in range(1, m):
			if grid_right[y][x] == 0:
				continue
			grid_right[y][x] += grid_right[y][x - 1]
	for x in range(m):
		for y in range(1, n):
			if grid_down[y][x] == 0:
				continue
			grid_down[y][x] += grid_down[y - 1][x]

	result = 0
	l = k * 2 + 1
	for y in range(k, n - k):
		for x in range(k, m - k):
			if grid_down[y + k][x] >= l and grid_right[y][x + k] >= l:
				result += 1

	print(result)


if __name__ == '__main__':
	main()
