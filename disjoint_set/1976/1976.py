import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    m = int(input())
    graph = []
    for _ in range(n):
        graph.append(list(map(int, input().split())))
    
    parent = [x for x in range(n + 1)]

    def find(x):
        if parent[x] == x:
            return x
        
        parent[x] = find(parent[x])
        return parent[x]

    def union(a, b):
        parent[find(a)] = find(b)

    for a in range(n):
        for b in range(n):
            if graph[a][b]:
                union(a + 1, b + 1)

    routes = list(map(int, input().split()))
    root = find(routes[0])
    if all(root == find(x) for x in routes):
        print('YES')
    else:
        print('NO')

if __name__ == "__main__":
    main()
