import sys
input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(100000)

def main():
    v, e = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(e)]
    edges.sort(key=lambda edge: edge[2])
    parent = list(range(v + 1))
    
    def find(child):
        if parent[child] != child:
            parent[child] = find(parent[child])
        
        return parent[child]
    
    def union(c1, c2):
        p1 = find(c1)
        p2 = find(c2)
        parent[p1] = parent[p2]

    result = 0
    for a, b, w in edges:
        if find(a) != find(b):
            union(a, b)
            result += w

    print(result)


if __name__ == "__main__":
    main()
