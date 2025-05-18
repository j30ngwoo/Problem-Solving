import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    a, b = input().split()
    result = float('inf')
    for start in range(len(b) - len(a) + 1):
        sliced_b = b[start:start + len(a)]
        diff = 0
        for i in range(len(a)):
            if a[i] != sliced_b[i]:
                diff += 1
        result = min(diff, result)
    print(result)

if __name__ == "__main__":
    main()
