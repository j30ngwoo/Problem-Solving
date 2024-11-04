import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n, m, r = map(int, input().split())
    items = [0] + list(map(int, input().split()))
    weights = [[0 if x == y else float('inf') for x in range(n + 1)] for y in range(n + 1)]
    for _ in range(r):
        a, b, l = map(int, input().split())
        weights[a][b] = weights[b][a] = l

    for mid in range(1, n + 1):
        for start in range(1, n + 1):
            for end in range(1, n + 1):
                weights[start][end] = min(weights[start][end], weights[start][mid] + weights[mid][end])
    
    #print('\n'.join(map(str, weights)))

    result = 0
    for start in range(1, n + 1):
        s = 0
        for end in range(1, n + 1):
            if weights[start][end] <= m:
                s += items[end]
        result = max(result, s)
    
    print(result)

if __name__ == "__main__":
    main()
