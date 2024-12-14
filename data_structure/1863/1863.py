import sys
input = lambda: sys.stdin.readline().strip()
from collections import deque

TOP = -1

def main():
    n = int(input())
    
    count = 0
    stk = deque([0])
    for _ in range(n):
        x, y = map(int, input().split())
        
        while y < stk[TOP]:
            stk.pop()
        
        if y != stk[TOP]:
            stk.append(y)
            count += 1
    
    print(count)

if __name__ == "__main__":
    main()
