import sys
input = lambda: sys.stdin.readline().strip()
from collections import deque

def main():
    n, m = map(int, input().split())

    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)

    incomings = {x: 0 for x in range(1, n + 1)}
    for a in range(1, n + 1):
        for b in graph[a]:
            incomings[b] += 1

    q = deque()
    for node in range(1, n + 1):
        if incomings[node] == 0:
            q.append(node)

    is_printed = [False] * (n + 1)
    while q:
        a = q.popleft()
        print(a, end=' ')
        is_printed[a] = True
        
        for node in graph[a]:
            incomings[node] -= 1
            if incomings[node] == 0:
                q.append(node)

    for i in range(1, n + 1):
        if not is_printed[i]:
            print(i, end=' ')

if __name__ == "__main__":
    main()
