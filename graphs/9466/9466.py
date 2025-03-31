import sys
input = lambda: sys.stdin.readline().rstrip()
sys.setrecursionlimit(200000)

def main():
    def dfs(i, members):
        nonlocal result
        is_visited[i] = True
        members.append(i)
        
        if is_visited[arr[i]]:
            if arr[i] in members:
                result += len(members) - members.index(arr[i])
        else:
            dfs(arr[i], members)

    for _ in range(int(input())):
        n = int(input())
        arr = [None] + list(map(int, input().split()))
        is_visited = [False] * (n + 1)
        result = 0

        for i in range(1, n + 1):
            if is_visited[i]:
                continue
            dfs(i, list())
        
        print(n - result)

if __name__ == "__main__":
    main()
