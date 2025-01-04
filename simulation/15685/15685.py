import sys
input = lambda: sys.stdin.readline().strip()

X = 0
Y = 1

def east(vertex): return [vertex[X], vertex[Y]]
def north(vertex): return [vertex[Y], -vertex[X]]
def west(vertex): return [-vertex[X], -vertex[Y]]
def south(vertex): return [-vertex[Y], vertex[X]]

TURNS = [east, north, west, south]

def main():
    curves = [[[0, 0], [1, 0]]]
    for _ in range(1, 11):
        axis = curves[-1][-1] 
        vertexs = curves[-1][:-1]
        curves.append(curves[-1][:])
        for vertex in vertexs[::-1]:
            new_vertex = [axis[X] - (vertex[Y] - axis[Y]), axis[Y] + (vertex[X] - axis[X])]
            curves[-1].append(new_vertex)

    grid = [[0 for _ in range(101)] for _ in range(101)]
    n = int(input())
    for _ in range(n):
        x, y, d, g = map(int, input().split())
        turned = list(map(TURNS[d], curves[g]))
        transed = list(map(lambda v: [v[X] + x, v[Y] + y], turned))
        for vertex in transed:
            grid[vertex[Y]][vertex[X]] = 1

    result = 0
    for r in range(100):
        for c in range(100):
            if sum([grid[r][c], grid[r + 1][c], grid[r][c + 1], grid[r + 1][c + 1]]) == 4:
                result += 1
    print(result)

if __name__ == "__main__":
    main()
