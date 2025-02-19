import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    fronts = dict()
    counts = dict()

    for i in range(n):
        if arr[i] in fronts:
            counts[arr[i]] = fronts[arr[i]]
            fronts[arr[i]] = len(fronts) - 1
        else:
            fronts[arr[i]] = len(fronts)

    print(sum(counts.values()))

main()