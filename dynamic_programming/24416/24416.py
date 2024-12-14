import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    arr = [1, 1]
    for i in range(2, n):
        arr.append(arr[i - 2] + arr[i - 1])
    
    print(arr[n - 1], n - 2)

if __name__ == "__main__":
    main()
