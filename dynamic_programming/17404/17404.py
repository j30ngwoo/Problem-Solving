import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    costs = [list(map(int, input().split())) for _ in range(n)]
    
    result = float('inf')
    for start in range(3):
        min_costs = [[float('inf') for _ in range(3)] for _ in range(n)]
        min_costs[0][start] = costs[0][start]
        for i in range(1, n):
            for color in range(3):
                min_costs[i][color] = costs[i][color] + min(min_costs[i - 1][other] for other in range(3) if color != other)
        result = min(result, min(min_costs[n - 1][other] for other in range(3) if start != other))

    print(result)
    
if __name__ == "__main__":
    main()
