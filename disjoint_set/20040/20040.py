import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n, m = map(int, input().split())
    parents = list(range(n + 1))
    ranks = [0] * (n + 1)

    def find(x):
        if parents[x] == x:
            return x
        parents[x] = find(parents[x])
        return parents[x]

    def union(x, y):
        p_x = find(x)
        p_y = find(y)

        if p_x == p_y:
            return
        
        if ranks[p_x] < ranks[p_y]:
            parents[p_x] = p_y
        elif ranks[p_x] > ranks[p_y]:
            parents[p_y] = p_x
        else:
            parents[p_y] = p_x
            ranks[p_x] += 1

    for round in range(1, m + 1):
        a, b = map(int, input().split())
        if find(a) == find(b):
            print(round)
            return
        else:
            union(a, b)
    
    print(0)

if __name__ == "__main__":
    main()
