import sys
input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
pos = 0
count = 0

board = []
for _ in range(n):
    board.append(int(input()))

for _ in range(m):
    count += 1

    pos += int(input())
    if pos >= n - 1:
        print(count)
        break

    pos += board[pos]
    if pos >= n - 1:
        print(count)
        break