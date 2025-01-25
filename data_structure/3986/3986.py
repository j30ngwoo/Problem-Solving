import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())

    result = 0
    for _ in range(n):
        s = input()
        stk = []
        for c in s:
            if stk and stk[-1] == c:
                stk.pop()
            else:
                stk.append(c)
        
        if not stk:
            result += 1
    
    print(result)

if __name__ == "__main__":
    main()
