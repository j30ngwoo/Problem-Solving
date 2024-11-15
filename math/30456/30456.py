import sys
input = lambda: sys.stdin.readline().strip()

def main():
    N, L = map(int, input().split())
    print('1' * (L - 1) + str(N))

if __name__ == "__main__":
    main()
