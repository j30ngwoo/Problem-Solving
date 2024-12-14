import sys
input = lambda: sys.stdin.readline().strip()
from collections import deque

INF = float('inf')
NUMBER = 0
HEIGHT = 1

def main():
    n = int(input())
    heights = list(map(int, input().split()))

    stk = deque()
    counts = [0] * (n + 1)
    mins = [INF] * (n + 1)
    
    for num in range(1, n + 1):
        h = heights[num - 1]
        while stk and stk[-1][HEIGHT] <= h:
            stk.pop()
        counts[num] += len(stk)
        if stk:
            mins[num] = stk[-1][NUMBER]
        stk.append((num, h))

    stk = deque()
    for num in range(n, 0, -1):
        h = heights[num - 1]
        while stk and stk[-1][HEIGHT] <= h:
            stk.pop()
        counts[num] += len(stk)
        if stk and abs(num - mins[num]) > abs(num - stk[-1][NUMBER]):
            mins[num] = stk[-1][NUMBER]
        stk.append((num, h))

    for i in range(1, n + 1):
        print(counts[i], end=' ')
        if counts[i] > 0:
            print(mins[i])
        else:
            print()


if __name__ == "__main__":
    main()
