import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    cnt2 = 0
    while n >= 0 and n % 5 != 0:
        n -= 2
        cnt2 += 1
    if n < 0:
        print(-1)
    else:
        print(n // 5 + cnt2)

if __name__ == "__main__":
    main()
