import sys
from bisect import bisect_left
input = lambda: sys.stdin.readline().strip()
def main():
	n = int(input())
	l = list(map(int, input().split()))
	arr = [l[0]]
	for i in range(n):
		if arr[-1] < l[i]:
			arr.append(l[i])
		else:
			arr[bisect_left(arr, l[i])] = l[i]
	print(len(arr))

main()
