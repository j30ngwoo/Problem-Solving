import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    result = 0
    temp = n
    while True:
        temp = temp % 10 * 10 + (temp // 10 + temp % 10) % 10
        result += 1
        if temp == n:
            break
    print(result)

if __name__ == "__main__":
    main()
