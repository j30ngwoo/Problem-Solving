import sys
input = lambda: sys.stdin.readline().strip()
from collections import deque

def left(x):
    return x - 1
def right(x):
    return x + 1
def double(x):
    return x * 2
FUNCS = [left, right, double]

def main():
    n, k = map(int, input().split())
    q = deque()
    q.append((n, 0))
    reverse_route = [-1] * 100_001

    def get_route(x):
        reverse_route[n] = -1
        result = [x]
        while reverse_route[x] != -1:
            result.append(reverse_route[x])
            x = reverse_route[x]
        result.reverse()
        return ' '.join(map(str, result))

    while q:
        pos, count = q.popleft()
        if pos == k:
            print(count)
            print(get_route(k))
            return
        for func in FUNCS:
            next_pos = func(pos)
            if 0 <= next_pos <= 100_000 and reverse_route[next_pos] == -1:
                reverse_route[next_pos] = pos
                q.append((next_pos, count + 1))
    
if __name__ == "__main__":
    main()
