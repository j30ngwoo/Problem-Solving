import sys
input = lambda: sys.stdin.readline().strip()
from itertools import accumulate 

def solve():
    k = int(input())
    chapters = list(map(int, input().split()))
    accum_sum = list(accumulate(chapters)) + [0]
    least_costs = [[float('inf') if x != y else 0 for x in range(k)] for y in range(k)]

    for b in range(1, k):
        for a in range(b - 1, -1, -1):
            for i in range(a, b):
                least_costs[a][b] = min(least_costs[a][b],  least_costs[a][i] + least_costs[i + 1][b] + accum_sum[b] - accum_sum[a - 1])
    
    print(least_costs[0][k - 1])


def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
