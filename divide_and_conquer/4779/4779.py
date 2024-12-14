import sys
input = lambda: sys.stdin.readline().strip()

def main():
    def recursion(left, right):
        length = right - left
        if length == 1:
            return
        
        one_third = length // 3

        for i in range(left + one_third, left + one_third * 2):
            arr[i] = ' '
        recursion(left, left + one_third)
        recursion(left + one_third * 2, right)

    while True:
        n = input()
        if not n:
            break
        n = int(n)

        arr = ['-'] * (3 ** n)
        recursion(0, 3 ** n)

        print(''.join(arr))


if __name__ == "__main__":
    main()
