n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))
result_idx = []
is_visited = [False for _ in range(n + 1)]

def print_idx():
	for i in result_idx:
		print(arr[i], end=' ')
	print()

def recursion():
	if len(result_idx) == m:
		print_idx()
		return
	for next in range(0, n):
		if is_visited[next]:
			continue
		result_idx.append(next)
		is_visited[next] = True
		recursion()
		result_idx.pop()
		is_visited[next] = False

recursion()