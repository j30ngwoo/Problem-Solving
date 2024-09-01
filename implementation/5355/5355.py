import sys
input = input = lambda: sys.stdin.readline().strip()

t = int(input())
for _ in range(t):
	ex = input().split()
	result = float(ex[0])
	for e in ex[1:]:
		if e == '@':
			result *= 3
		elif e == '%':
			result += 5
		else:
			result -= 7
	print(f"{result:.2f}")