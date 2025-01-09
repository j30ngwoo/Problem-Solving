import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n, m = map(int, input().split())
    arr = [int(input()) for _ in range(n)]

    range_sum = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    for a in range(n):
        for b in range(a + 1, n + 1):
            range_sum[a][b] = range_sum[a][b - 1] + arr[b - 1]
    
    for l in range(2, n + 1):
        for start in range(n - l + 1):
            stop = start + l
            range_sum[start][stop] = max(range_sum[start][stop], range_sum[start + 1][stop], range_sum[start][stop - 1])

    # range_max[count][stop] = max(range_max[count][stop], range_max[count - 1][mid] + range_sum[mid + 1][stop] (1 <= mid < stop - 1)
    range_max = [[], range_sum[0][:]] + [[float('-inf') for _ in range(n + 1)] for _ in range(m - 1)]
    for count in range(2, m + 1):
        for stop in range(1, n + 1):
            for mid in range(1, stop - 1):
                range_max[count][stop] = max(range_max[count][stop], range_max[count - 1][mid] + range_sum[mid + 1][stop])

    print(range_max[m][n])

if __name__ == "__main__":
    main()
