import sys
input = lambda: sys.stdin.readline().strip()
from copy import deepcopy
from collections import deque 

DY = [0, 0, -1, 1]
DX = [-1, 1, 0, 0]
Y, X = 0, 1

def main():
	n, m = map(int, input().split())
	grid = [list(map(int, input())) for _ in range(n)]
	visited = [[False for _ in range(m)] for _ in range(n)]
	results = deepcopy(grid)

	for sy in range(n):
		for sx in range(m):
			if grid[sy][sx] == 1 or visited[sy][sx]:
				continue
			now_area = set([(sy, sx)])
			q = deque([(sy, sx)])
			while q:
				y, x = q.popleft()
				for d in range(4):
					ny, nx = y + DY[d], x + DX[d]
					if 0 <= ny < n and 0 <= nx < m and grid[ny][nx] == 0 and (ny, nx) not in now_area:
						q.append((ny, nx))
						now_area.add((ny, nx))
						visited[ny][nx] = True
			# print(now_area)	
			added = set() 
			for y, x in now_area:
				for d in range(4):
					ny, nx = y + DY[d], x + DX[d]
					if 0 <= ny < n and 0 <= nx < m and grid[ny][nx] == 1 and (ny, nx) not in added:
						# print(f'{ny}, {nx} += {len(now_area)}')
						results[ny][nx] += len(now_area)
						results[ny][nx] %= 10
						added.add((ny, nx))

	print('\n'.join(map(lambda l: ''.join(map(str, l)), results)))

main()