import sys
input = lambda: sys.stdin.readline().strip()

print(''.join(sorted(list(input()), reverse=True)))