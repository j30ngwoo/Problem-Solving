import sys
input = lambda: sys.stdin.readline().strip()
sys.setrecursionlimit(100000)

from collections import deque

def main():
	n, q = map(int, input().split())
	graph = [[] for _ in range(n + 1)]
	for _ in range(n - 1):
		a, b, w = map(int, input().split())
		graph[a].append((b, w))
		graph[b].append((a, w))
	
	# def dfs(a, least):
	# 	nonlocal count, is_visited
	# 	if is_visited[a]:
	# 		return
	# 	is_visited[a] = True
	# 	if least >= k:
	# 		count += 1
	# 	for b, w in graph[a]:
	# 		if not is_visited[b]:
	# 			dfs(b, min(w, least))

	def bfs(start):
		nonlocal count
		is_visited = [False] * (n + 1)
		q = deque()
		q.append((start, float('inf')))
		while q:
			a, least = q.popleft()
			if is_visited[a]:
				continue
			is_visited[a] = True
			if least >= k:
				count += 1
			for b, w in graph[a]:
				if not is_visited[b]:
					q.append((b, min(w, least)))

	for _ in range(q):
		k, v = map(int, input().split())
		count = -1
		bfs(v)
		print(count)

main()