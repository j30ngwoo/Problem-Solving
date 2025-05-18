import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n, arr, x = int(input()), sorted(list(map(int, input().split()))), int(input())
    
    l, r = 0, n - 1
    result = 0
    while l < r:
        s = arr[l] + arr[r]
        if s == x:
            result += 1
            l += 1
            r -= 1
        elif s < x:
            l += 1
        else:
            r -= 1
    print(result)

if __name__ == "__main__":
    main()
