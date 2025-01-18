import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    N, C = map(int, input().split())
    arr = list(map(int, input().split()))
    d = dict()
    for e in arr:
        if e in d:
            d[e] += 1
        else:
            d[e] = 1
    
    for k, v in sorted(d.items(), key=lambda x: -x[1]):
        print((str(k) + ' ') * v, end='')

if __name__ == "__main__":
    main()
