import sys
input = lambda: sys.stdin.readline().strip()

X = 0
A = 1

def main():
    n = int(input())
    towns = [list(map(int, input().split())) for _ in range(n)]
    towns.sort()

    left = 0
    right = sum(town[A] for town in towns)
    for town in towns:
        left += town[A]
        right -= town[A]
        if left >= right:
            break

    print(town[X])

if __name__ == "__main__":
    main()
