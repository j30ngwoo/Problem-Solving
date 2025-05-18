n = int(input())
a, b = 1, 2

for _ in range(n - 1):
    new = (a + b) % 15746
    a = b
    b = new

print(a)
