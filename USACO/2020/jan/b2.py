import sys
input = lambda: sys.stdin.readline().rstrip()
MAX_ARR = [1001]

def get_a(first):
    is_visited = [False for _ in range(n + 1)]
    is_visited[first] = True
    a = [first]
    for i in range(n - 1):
        next = b[i] - a[-1]
        if not 1 <= next <= n:
            return MAX_ARR
        if is_visited[next]:
            return MAX_ARR
        a.append(next)
        is_visited[next] = True
    return a

def main():
    global n, b
    n, b = int(input()), list(map(int, input().split()))
    result = MAX_ARR
    
    for first in range(1, n + 1):
        result = min(get_a(first), result)

    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()
