import sys
input = sys.stdin.readline

n, m = map(int, input().split())
result_arr = [0]

def print_idx():
	for e in result_arr[1:]:
		print(e, end=' ')
	print()

def recursion(layer):
	if len(result_arr) == m + 1:
		print_idx()
		return
	for next in range(result_arr[-1] + 1, n - layer + 1):
		result_arr.append(next)	
		recursion(layer - 1)
		result_arr.pop()

recursion(m - 1)