import sys
input = lambda: sys.stdin.readline().strip()
from collections import deque 

H = 0
I = 1

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    stk = deque()
    stk.append((float('inf'), 0))

    for i, e in enumerate(arr):
        while stk[-1][H] < e:
            stk.pop()
        print(stk[-1][I], end=' ')
        stk.append((e, i + 1))

if __name__ == "__main__":
    main()
