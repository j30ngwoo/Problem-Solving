import sys
input = lambda: sys.stdin.readline().rstrip()
from copy import deepcopy 

L, R = 0, 1
COST, STATUS = 0, 1

def get_cost(a, b):
	if a == 0 or b == 0:
		return 2
	if max(a, b) - min(a, b) == 1 or sorted([a, b]) == [1, 4]:
		return 3
	return 4

def main():
	orders = list(map(int, input().split()))[:-1]
	min_costs = [[float('inf') for _ in range(5)] for _ in range(5)]
	min_costs[0][0] = 0

	for order in orders:
		


main()
