import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    
    last_indexs = [-1] * (max(arr) + 1)
    result = 0
    accum_len = 0

    for index, value in enumerate(arr):
        accum_len = min(accum_len + 1, index - last_indexs[value])
        last_indexs[value] = index
        result += accum_len

    print(result)

if __name__ == "__main__":
    main()
