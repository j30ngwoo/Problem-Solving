import sys
input = lambda: sys.stdin.readline().strip()
from math import gcd

MOD = 1000000007

def power(n, p):
        if p == 1:
            return n % MOD
        if p % 2 == 0:
            return power(n, p // 2) ** 2 % MOD
        else:
            return n * power(n, p - 1) % MOD

def main():
    m = int(input())
    result = 0
    for _ in range(m):
        a, b = map(int, input().split())
        result += b * power(a, MOD - 2) % MOD

    print(result % MOD)


if __name__ == "__main__":
    main()
