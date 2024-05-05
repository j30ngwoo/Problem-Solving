n, k = map(int, input().split())

def f(a):
    result = 1
    for i in range(1, a + 1):
        result *= i
    return result

print(f(n) // (f(n - k) * f(k)))