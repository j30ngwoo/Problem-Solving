import sys
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    coords = []
    for _ in range(n):
        coords.append(list(map(int, input().split())))
    
    X = 0
    Y = 1
    result = 0
    for i in range(-1, n - 1):
        result += coords[i][X] * coords[i + 1][Y] 
        result -= coords[i + 1][X] * coords[i][Y]
    
    print(f'{(abs(result) / 2):.1f}')

if __name__ == "__main__":
    main()
