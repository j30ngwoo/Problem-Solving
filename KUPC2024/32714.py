import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
	n = int(input())

	if n == 2:
		print(1)
	elif n == 3:
		print(3)
	else:
		print(3 * n - 4)

if __name__ == '__main__':
	main()
