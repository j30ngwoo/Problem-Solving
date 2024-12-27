import sys
input = lambda: sys.stdin.readline().strip()
from queue import PriorityQueue

def main():
    n = int(input())
    m = int(input())
    graph = [[] for _ in range(n + 1)]
    for _ in range(m):
        s, e, w = map(int, input().split())
        graph[s].append((e, w))
    
    a, b = map(int, input().split())

    dists = {node: float('inf') for node in range(1, n + 1)}
    prevs = {node: None for node in range(1, n + 1)}
    pq = PriorityQueue()
    pq.put_nowait((0, a)) # dist, node
    while pq:
        now_dist, now_node = pq.get_nowait()
        if now_node == b:
            print(now_dist)
            break

        if dists[now_node] < now_dist:
            continue

        for next_node, w in graph[now_node]:
            next_dist = now_dist + w
            if next_dist < dists[next_node]:
                dists[next_node] = next_dist
                prevs[next_node] = now_node
                pq.put_nowait((next_dist, next_node))

    node = b
    path = []
    count = 1
    while node != a:
        path.append(node)
        node = prevs[node]
        count += 1
    print(count)
    print(' '.join(map(str, (path + [a])[::-1])))


if __name__ == "__main__":
    main()
