import sys
input = lambda: sys.stdin.readline().strip()

def main():
    while True:
        arr = list(map(int, input().split()))
        if 0 == arr[0] == arr[1] == arr[2]:
            break

        arr.sort()
        if not arr[0] + arr[1] > arr[2]:
            print('Invalid') 
        elif arr[0] == arr[1] == arr[2]:
            print('Equilateral')
        elif arr[0] == arr[1] or arr[1] == arr[2]:
            print('Isosceles')
        else:
            print('Scalene')
        

main()
