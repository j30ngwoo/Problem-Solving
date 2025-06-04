import sys
input = lambda: sys.stdin.readline().rstrip()
INF = float('inf')
sys.setrecursionlimit(1000000)

def is_repeated(sub_arr, rep_len):
    repeat = sub_arr[:rep_len]
    for i in range(rep_len, len(sub_arr), rep_len):
        if repeat != sub_arr[i:i + rep_len]:
            return False
    return True

def get_min(l, r):
    #print(l, r)
    if mins[l][r] != INF:
        return mins[l][r]

    tot_len = r - l
    for rep_len in range(1, tot_len // 2 + 1):
        if tot_len % rep_len == 0 and is_repeated(arr[l:r], rep_len):
            mins[l][r] = min(mins[l][r], get_min(l, l + rep_len))
    
    for m in range(l + 1, r):
        mins[l][r] = min(mins[l][r], get_min(l, m) + get_min(m, r))
    
    return mins[l][r]

def solve():
    n, k = map(int, input().split())
    
    global arr, mins
    arr = list(map(int, input().split()))
    mins = [[INF] * (n + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        mins[i][i] = 0
    for i in range(n):
        mins[i][i + 1] = 1
    
    print("YES" if get_min(0, n) <= k else "NO")

def main():
    for _ in range(int(input())):
        solve()

if __name__ == "__main__":
    main()
