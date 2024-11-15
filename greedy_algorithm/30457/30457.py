import sys
input = lambda: sys.stdin.readline().strip()

def main():
    N = int(input())
    arr = list(map(int, input().split()))

    arr.sort()
    result = 0
    is_selected = [False] * N
    for _ in range(2):
        max_ = 0
        for i in range(N):
            if not is_selected[i] and max_ < arr[i]:
                result += 1
                max_ = arr[i]
                is_selected[i] = True

    print(result)

if __name__ == "__main__":
    main()
