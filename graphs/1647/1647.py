import sys
input = lambda: sys.stdin.readline().rstrip()
from heapq import heappop, heappush


def main():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        a, b, c = map(int, input().split())
        graph[a].append((c, b))
        graph[b].append((c, a))

    pq = [(0, 1)]
    visited = set()
    weights = []
    while pq and len(visited) < n:
        weight, node = heappop(pq)

        if node in visited:
            continue

        visited.add(node)
        weights.append(weight)

        for next_weight, next_node in graph[node]:
            if next_node in visited:
                continue
            heappush(pq, (next_weight, next_node))

    print(sum(weights) - max(weights))


if __name__ == "__main__":
    main()
