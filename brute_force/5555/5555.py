import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    p = input()
    n = int(input())
    count = 0

    for _ in range(n):
        if p in input() * 2:
            count += 1

    print(count)

if __name__ == "__main__":
    main()
