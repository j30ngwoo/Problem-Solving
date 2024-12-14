import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    dancing = set(['ChongChong'])
    
    for _ in range(n):
        a, b = input().split()
        if a in dancing:
            dancing.add(b)
        elif b in dancing:
            dancing.add(a)
    
    print(len(dancing))

if __name__ == "__main__":
    main()
