import sys
input = lambda: sys.stdin.readline().rstrip()

def is_goodword(s):
    stk = []
    for c in s:
        if stk and stk[-1] == c:
            stk.pop()
        else:
            stk.append(c)
    
    if stk:
        return False
    else:
        return True

def main():
    n = int(input())

    result = 0
    for _ in range(n):
        if is_goodword(input()):
            result += 1

    print(result)

if __name__ == "__main__":
    main()
