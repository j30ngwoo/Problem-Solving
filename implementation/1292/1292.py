import sys
input = lambda: sys.stdin.readline().strip()

def main():
    arr = [0] * 1001
    count = 0
    now_num = 1
    for i in range(1, 1001):
        arr[i] = now_num
        count += 1
        if count == now_num:
            now_num += 1
            count = 0
    
    a, b = map(int, input().split())
    print(sum(arr[a:(b + 1)]))

if __name__ == "__main__":
    main()
