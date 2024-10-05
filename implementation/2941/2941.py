import sys
input = lambda: sys.stdin.readline().strip()

w = input()
l = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
count = 0
i = 0

while i < len(w):
    found = False
    for c_alpha in l:
        if w[i:i+len(c_alpha)] == c_alpha:
            i += len(c_alpha)
            found = True
            break
    if not found:
        i += 1
    count += 1

print(count)