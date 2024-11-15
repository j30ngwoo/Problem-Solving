import sys
input = lambda: sys.stdin.readline().strip()

def main():
    N, M, R = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    A.sort()
    B.sort()
    
    widths = set()
    for l in range(N - 1):
        for r in range(l + 1, N):
            widths.add(A[r] - A[l])
    widths = sorted(list(widths))

    R *= 2
    result = -1
    def bisearch(h, left, right):
        nonlocal result
        if left > right:
            return

        mid = (left + right) // 2
        area = widths[mid] * h
        if R < area:
            bisearch(h, left, mid - 1)
        else:
            result = max(result, area)
            bisearch(h, mid + 1, right)
    

    for height in B:
        bisearch(height, 0, len(widths) - 1)
    
    if result == -1:
        print(-1)
    else:
        print(round(result / 2, 1))

if __name__ == "__main__":
    main()
