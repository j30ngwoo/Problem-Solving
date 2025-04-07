import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n, u = map(int, input().split())
    half = n // 2
    grid = [list(input()) for _ in range(n)]

    def flip(i):
        return n - i - 1

    def get_reflected(y, x):
        return (y, x), (flip(y), x), (y, flip(x)), (flip(y), flip(x))
    
    def get_origin(y, x):
        return (y if y < half else flip(y), x if x < half else flip(x))

    dots = [[0 for _ in range(half)] for _ in range(half)]
    result = 0
    for orig_y in range(half):
        for orig_x in range(half):
            for y, x in get_reflected(orig_y, orig_x):
                if grid[y][x] == '.':
                    dots[orig_y][orig_x] += 1
            result += min(dots[orig_y][orig_x], 4 - dots[orig_y][orig_x])
    print(result)
    
    # updates
    for _ in range(u):
        y, x = map(lambda i: int(i) - 1, input().split())
        orig_y, orig_x = get_origin(y, x)
        orig_dot = dots[orig_y][orig_x]
        if grid[y][x] == '.':
            grid[y][x] = '#'
            dots[orig_y][orig_x] -= 1
        else:
            grid[y][x] = '.'
            dots[orig_y][orig_x] += 1
        result = result - min(orig_dot, 4 - orig_dot) + min(dots[orig_y][orig_x], 4 - dots[orig_y][orig_x])
        print(result)

    #print('\n'.join(map(str, dots)))

main()