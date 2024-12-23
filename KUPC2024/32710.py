import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
	n = int(input())
	l = set([1])

	for i in range(2, 10):
		l.add(i)
		for j in range(1, 10):
			l.add(i * j)
	
	if n in l:
		print(1)
	else:
		print(0)


if __name__ == '__main__':
	main()