import sys
input = lambda: sys.stdin.readline().rstrip()

def get_cost(a, b):
	if a == 0:
		return 2
	if a == b:
		return 1
	if abs(a - b) == 2:
		return 4
	return 3

def main():
	orders = list(map(int, input().split()))[:-1]
	cost_remained = [[[float('inf') for _ in range(5)] for _ in range(5)] for _ in range(len(orders) + 1)]
	cost_remained[0][0][0] = 0

	for i in range(len(orders)):
		next_step = orders[i]
		for l in range(5):
			for r in range(5):
				cost_remained[i + 1][l][next_step] = min(cost_remained[i + 1][l][next_step], cost_remained[i][l][r] + get_cost(r, next_step))
				cost_remained[i + 1][next_step][r] = min(cost_remained[i + 1][next_step][r], cost_remained[i][l][r] + get_cost(l, next_step))

	# for i in range(len(orders)):
	# 	next_step = orders[i]
	# 	for l in range(5):
	# 		for r in range(5):
	# 			print(cost_remained[i + 1][l][r], end=' ')
	# 		print()
	# 	print()

	print(min(min(row for row in cost_remained[len(orders)])))

main()
