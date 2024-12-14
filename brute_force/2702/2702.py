import sys
input = lambda: sys.stdin.readline().strip()

def main():
    t = int(input())
    for _ in range(t):
        a, b = map(int, input().split())
        max_ = max(a, b)
        min_ = min(a, b)
        
        i = 1
        while True:
            lcm = max_ * i
            if lcm % min_ == 0:
                print(lcm, end=' ')
                break
            i += 1
        
        i = 1
        while True:
            if min_ % i == 0:
                gcd = min_ // i
                if max_ % gcd == 0:
                    print(gcd)
                    break
            i += 1
if __name__ == "__main__":
    main()
