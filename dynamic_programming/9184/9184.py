import sys
input = lambda: sys.stdin.readline().strip()
def main():
	table = dict()

	def w(a, b, c):
		if (a, b, c) not in table: 
			if a <= 0 or b <= 0 or c <= 0:
				table[(a, b, c)] = 1
			elif a > 20 or b > 20 or c > 20:
				table[(a, b, c)] = w(20, 20, 20)
			elif a < b and b < c:
				table[(a, b, c)] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
			else:
				table[(a, b, c)] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
		return table[(a, b, c)]


	while True:
		a, b, c = map(int, input().split())
		if a == b == c == -1:
			return
		print(f'w({a}, {b}, {c}) = {w(a, b, c)}')

main()
