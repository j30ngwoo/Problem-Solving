import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
	n = int(input())
	arr = list(map(int, input().split()))
	count_odd = sum(e % 2 for e in arr)

	if count_odd == 0 and n == 1 or count_odd == 2 and arr[0] % 2 == 1 and arr[n - 1] % 2 == 1:
		print(0)
	else:
		print(1)


if __name__ == '__main__':
	main()
