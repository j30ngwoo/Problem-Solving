n = int(input())
arr = []
is_visited = [False for _ in range(n + 1)]

def print_arr(arr):
	for e in arr:
		print(e, end=' ')
	print()

def recursion():
	if len(arr) == n:
		print_arr(arr)
		return
	for i in range(1, n + 1):
		if is_visited[i] == False:
			arr.append(i)
			is_visited[i] = True
			recursion()
			is_visited[arr.pop()] = False
recursion()
