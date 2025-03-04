import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    
    result_sum, result_arr = float('inf'), None
    for a in range(n - 2):
        b = a + 1
        c = n - 1
        while b < c:
            s = arr[a] + arr[b] + arr[c]
            if abs(s) < result_sum:
                result_sum = abs(s)
                result_arr = arr[a], arr[b], arr[c]
            if s < 0:
                b += 1
            else:
                c -= 1

    print(' '.join(map(str, result_arr)))

if __name__ == "__main__":
    main()
