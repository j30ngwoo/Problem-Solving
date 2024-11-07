import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    arr = list(map(int, input().split()))

    l = 0
    r = n - 1
    abs_min = float('inf')
    result = (None, None)
    while l < r:
        s = arr[l] + arr[r]
        abs_s = abs(s)
        if abs_s < abs_min:
            result = arr[l], arr[r]
            abs_min = abs_s

        if s < 0:
            l += 1
        elif 0 < s:
            r -= 1
        else:
            break
    
    print(result[0], result[1])

if __name__ == "__main__":
    main()
