import sys
input = lambda: sys.stdin.readline().strip()
from heapq import heappush, heappop

def main():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        a, b, w = map(int, input().split())
        graph[a].append((b, w))
        graph[b].append((a, w))
    
    is_visited = [False for _ in range(n + 1)]
    pq = [(0, 1)] # W, N
    while pq:
        weight, node = heappop(pq)

        if is_visited[node]:
            continue
        is_visited[node] = True

        if node == n:
            print(weight)
            break

        for next_node, next_weight in graph[node]:
            if not is_visited[next_node]:
                heappush(pq, (weight + next_weight, next_node))


if __name__ == "__main__":
    main()
