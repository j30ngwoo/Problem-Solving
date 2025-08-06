import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    
    counts = [0 for _ in range(n + 1)]
    for e in arr:
        counts[e] += 1

    less_than = [0 for _ in range(n + 1)]
    for i in range(1, n + 1):
        if counts[i - 1] > 0:
            less_than[i] = less_than[i - 1] + 1
        else:
            less_than[i] = less_than[i - 1]

    # print(counts)
    # print(less_than)

    for i in range(n + 1):
        print(max(counts[i], i - less_than[i]))


if __name__ == "__main__":
    main()
