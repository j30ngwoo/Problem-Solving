import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
arr = list(map(int, input().split()))
add, sub, mul, div = list(map(int, input().split()))
result = []

def recursion(i, v):
    global add, sub, mul, div
    if i == n:
        result.append(v)
        return
    if add >= 1:
        add -= 1
        recursion(i + 1, v + arr[i])
        add += 1
    if sub >= 1:
        sub -= 1
        recursion(i + 1, v - arr[i])
        sub += 1
    if mul >= 1:
        mul -= 1
        recursion(i + 1, v * arr[i])
        mul += 1
    if div >= 1:
        div -= 1
        if v < 0 and arr[i] > 0:
            recursion(i + 1, -(-v // arr[i]))
        else:
            recursion(i + 1, v // arr[i])
        div += 1

recursion(1, arr[0])
print(max(result))
print(min(result))