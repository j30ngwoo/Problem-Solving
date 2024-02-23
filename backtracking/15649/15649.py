import sys
input = sys.stdin.readline

n, m = map(int, input().split())
is_visited = [False for _ in range(n + 1)]
result_arr = []

def print_idx():
	for e in result_arr:
		print(e, end=' ')
	print()

def recursion():
	if len(result_arr) == m:
		print_idx()
		return
	for next in range(1, n + 1):
		if is_visited[next]:
			continue
		result_arr.append(next)
		is_visited[next] = True
		recursion()
		result_arr.pop()
		is_visited[next] = False

recursion()