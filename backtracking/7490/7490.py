import sys
input = lambda: sys.stdin.readline().strip()

def main():
    t = int(input())

    def oper():
        result = 0
        value = n
        for i in range(n - 2, -1, -1):
            if opers[i] == ' ':
                value += (10 ** len(str(value))) * (i + 1)
            elif opers[i] == '+':
                result += value
                value = i + 1
            else: # '-'
                result -= value
                value = i + 1
        
        result += value
        return result

    def recursion(depth):
        if depth == n - 1:
            if oper() == 0:
                for i in range(n - 1):
                    print(i + 1, end='')
                    print(opers[i], end='')
                print(n)
            return

        for o in [' ', '+', '-']:
            opers.append(o)
            recursion(depth + 1)
            opers.pop()

    for _ in range(t):
        n = int(input())
        opers = []
        recursion(0)
        print()

if __name__ == "__main__":
    main()
