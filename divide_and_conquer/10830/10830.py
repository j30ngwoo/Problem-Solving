import sys
input = lambda: sys.stdin.readline().strip()
from copy import deepcopy

def main():
    n, b = map(int, input().split())
    a = []
    for _ in range(n):
        a.append(list(map(int, input().split())))

    def matrix_mul(a, b):
        result = [[None for _ in range(n)] for _ in range(n)]
        for y in range(n):
            for x in range(n):
                result[y][x] = sum(a[y][i] * b[i][x] for i in range(n)) % 1000
        return result
    
    table = {1 : a} # ^2^i

    def recursion(p):
        if p in table:
            return table[p]
        
        next_p = p // 2
        table[p] = matrix_mul(recursion(next_p), recursion(p - next_p))
        return table[p]

    for row in recursion(b):
        row = map(lambda x: x % 1000, row)
        print(' '.join(map(str, row)))

if __name__ == "__main__":
    main()
