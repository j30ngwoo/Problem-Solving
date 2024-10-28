import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
paper = [list(map(int, input().split())) for _ in range(n)]
result = [0, 0, 0] # 0, 1, -1

def is_same_paper(x, y, l):
    check = paper[y][x]
    for dy in range(l):
        for dx in range(l):
            if check != paper[y + dy][x + dx]:
                return False
    return True

def recursion(x, y, l):
    if is_same_paper(x, y, l):
        result[paper[y][x]] += 1
    else:
        next_l = l // 3
        for dy in range(3):
            for dx in range(3):
                next_x = x + next_l * dx
                next_y = y + next_l * dy
                recursion(next_x, next_y, next_l)

recursion(0, 0, n)

print(result[-1])
print(result[0])
print(result[1])