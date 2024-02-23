n, r = map(int, input().split())
arr = sorted(list(map(int, input().split())))
result_idx = [-1]

def print_idx():
	for i in result_idx[1:]:
		print(arr[i], end=' ')
	print()

def recursion(layer):
	if len(result_idx) == r + 1:
		print_idx()
		return
	for i in range(result_idx[-1] + 1, n - r + layer + 1):
		result_idx.append(i)
		recursion(layer + 1)
		result_idx.pop()

recursion(0)