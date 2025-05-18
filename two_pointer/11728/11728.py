import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    input(), print(' '.join(map(str, sorted(list(map(int, input().split())) + list(map(int, input().split()))))))

if __name__ == "__main__":
    main()
