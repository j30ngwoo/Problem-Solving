import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    k = int(input())

    def get_k(x):
        result = 0
        for i in range(1, min(n, x) + 1):
            result += min(n, x // i)
        return result

    l = 1
    r = k
    while l < r:
        # b[k] == x
        x = (l + r) // 2
        if k <= get_k(x):
            r = x
        else:
            l = x + 1
    
    print(l)

if __name__ == "__main__":
    main()
