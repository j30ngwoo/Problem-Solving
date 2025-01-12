import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    k = int(input())
    sensors = sorted(list(set(map(int, input().split()))))
    
    dists = []
    for i in range(len(sensors) - 1):
        dists.append(sensors[i + 1] - sensors[i])
    dists.sort()

    for _ in range(k - 1):
        if dists:
            dists.pop()

    print(sum(dists))


if __name__ == "__main__":
    main()
