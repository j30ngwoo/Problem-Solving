import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    arr = []
    for _ in range(n):
        arr.append(int(input()))

    counts = [1] * n
    for now in range(n):
        for prev in range(now):
            if arr[prev] < arr[now]:
                counts[now] = max(counts[prev] + 1, counts[now])
    
    print(n - max(counts))


if __name__ == "__main__":
    main()
