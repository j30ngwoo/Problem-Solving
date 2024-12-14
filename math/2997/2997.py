import sys
input = lambda: sys.stdin.readline().strip()

def main():
    arr = list(map(int, input().split()))
    arr.sort()

    if arr[1] - arr[0] == arr[2] - arr[1]:
        print(arr[1] - arr[0])
    else:
        print(arr[0] + arr[2] - arr[1])

if __name__ == "__main__":
    main()
