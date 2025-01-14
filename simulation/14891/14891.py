import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    gears = []
    for i in range(4):
        gears.append(list(map(int, list(input()))))
    
    def turn(index, direction):
        if is_visited[index]:
            return
        is_visited[index] = True

        if index >= 1 and gears[index][6] != gears[index - 1][2]:
            turn(index - 1, direction * -1)
        if index <= 2 and gears[index][2] != gears[index + 1][6]:
            turn(index + 1, direction * -1)

        if direction == 1:
            gears[index].insert(0, gears[index].pop())
        else:
            gears[index].append(gears[index].pop(0))

    k = int(input())
    for _ in range(k):
        i, d = map(int, input().split())
        is_visited = [False] * 4
        turn(i - 1, d)

    print(sum(gears[i][0] * (2 ** i) for i in range(4)))


if __name__ == "__main__":
    main()
