import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = 0
    diff = 1000
    result = 0
    for i in range(10):
        n += int(input())
        if abs(n - 100) <= diff:
            result = n
            diff = abs(n - 100)

    print(result)

if __name__ == "__main__":
    main()
