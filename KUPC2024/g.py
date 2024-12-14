import sys
input = lambda: sys.stdin.readline().rstrip()

def get_area(n):
	if n % 4 == 0:
		return ((n // 4) ** 2)
	elif n % 2 == 0:
		return ((n // 4 + 1) + n // 4)

def main():
	n = int(input())
	if n < 4:
		print(0)
	elif n % 2 == 0:
		print(get_area(n))
	else:
		print(get_area(n - 1) + 1)

12: 3 3 3 3 -> 3 * 3
14: 4 3 4 3 -> 4 * 3
16: 4 4 4 4
18: 5 4 5 4

if __name__ == '__main__':
	main()


