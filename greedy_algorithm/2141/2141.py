import sys
input = lambda: sys.stdin.readline().strip()

X = 0
A = 1

def main():
    n = int(input())
    towns = []
    for _ in range(n):
        towns.append(list(map(int, input().split())))
    towns.sort()

    left = 0
    right = sum(town[A] for town in towns)
    for i in range(n):
        left += towns[i][A]
        right -= towns[i][A]
        if left >= right:
            break

    print(towns[i][X])

if __name__ == "__main__":
    main()
