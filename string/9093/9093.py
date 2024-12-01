import sys
input = lambda: sys.stdin.readline().strip()

def main():
    for _ in range(int(input())): print(' '.join(map(lambda s: s[::-1], input().split())))

if __name__ == "__main__":
    main()
