import sys
input = lambda: sys.stdin.readline().strip()

def factors(x):
    l = []
    for i in range(1, x):
        if x % i == 0:
            l.append(i)
    return l

def is_perfect(x):
    if sum(factors(x)) == x:
        return True
    else:
        return False

while True:
    n = int(input())
    if n == -1:
        break
    if is_perfect(n):
        print(n, "=", " + ".join(map(str, factors(n))))
    else:
        print(n, "is NOT perfect.")
