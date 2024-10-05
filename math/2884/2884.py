h, m = map(int, input().split())

m -= 45

if m < 0:
    m += 60
    h -= 1

if h == -1:
    h = 23

print(h, m)