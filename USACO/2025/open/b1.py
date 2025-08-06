n, m = map(int, input().split())
chart = [list(input()) for _ in range(n)]

for y in range(n - 1):
    for x in range(y + 1, n):
        if chart[x][y] == 'W':
            chart[y].append('L')
        elif chart[x][y] == 'L':
            chart[y].append('W')
        else:
            chart[y].append('D')

#print(chart)

for _ in range(m):
    s1, s2 = map(lambda x: int(x) - 1, input().split())
    have_to_win = 0
    for i in range(n):
        if chart[i][s1] == chart[i][s2] == 'W':
            have_to_win += 1
    
    print(n ** 2 - (n - have_to_win) ** 2)

