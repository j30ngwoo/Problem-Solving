import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    a, b, c, m = map(int, input().split())
    p = 0
    work = 0
    for i in range(24):
        if p + a <= m:
            p += a
            work += b
        else:
            p = max(p - c, 0)
    print(work)

if __name__ == "__main__":
    main()
