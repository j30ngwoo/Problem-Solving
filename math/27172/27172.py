import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    m = max(arr)
    s = set(arr)
    result = [0] * 1_000_001

    for e in arr:
        for mul in range(2 * e, m + 1, e):
            if mul in s:
                result[e] += 1
                result[mul] -= 1
    
    for e in arr:
        print(result[e], end=' ')

if __name__ == "__main__":
    main()
