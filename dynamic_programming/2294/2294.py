import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n, k = map(int, input().split())
    coins = list(set(int(input()) for _ in range(n)))
    counts = [0] + [float('inf')] * k
    
    for i in range(1, k + 1):
        for coin in coins:
            if coin <= i:
                counts[i] = min(counts[i], counts[i - coin] + 1)

    if counts[k] == float('inf'):
        print(-1)
    else:
        print(counts[k])

if __name__ == "__main__":
    main()
