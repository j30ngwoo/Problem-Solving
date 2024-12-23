import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
	n, k = map(int, input().split())
	arr = list(map(int, input().split()))

	accum_right = arr[:]
	accum_left = arr[:]
	for i in range(1, n):
		accum_right[i] += accum_right[i - 1]
	for i in range(n - 2, -1, -1):
		accum_left[i] += accum_left[i + 1]

	for i in range(n):
		accum_right[i] += max(0, arr[i] * (k - i - 1))
		accum_left[i] += max(0, arr[i] * (k - n + i))

	print(max(max(accum_right[:k]), max(accum_left[n - k:])))


if __name__ == '__main__':
	main()