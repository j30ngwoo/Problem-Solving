import sys
input = lambda: sys.stdin.readline().strip()

def main():
    print('\n'.join(f"Case #{i}: {sum(map(int, input().split()))}" for i in range(1, int(input()) + 1)))

if __name__ == "__main__":
    main()
