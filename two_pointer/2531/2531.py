import sys
input = lambda: sys.stdin.readline().strip()

def main():
    N, d, k, c = map(int, input().split())
    sushis = []
    for _ in range(N):
        sushis.append(int(input()))
    sushis *= 2
    
    table = dict()
    for i in range(k):
        if sushis[i] in table:
            table[sushis[i]] += 1
        else:
            table[sushis[i]] = 1
            
    result = 0
    for right in range(k, N + k):
        if c not in table:
            result = max(result, len(table) + 1)
        else:
            result = max(result, len(table))
        left = right - k
        if table[sushis[left]] == 1:
            table.pop(sushis[left])
        else:
            table[sushis[left]] -= 1
        if sushis[right] in table:
            table[sushis[right]] += 1
        else:
            table[sushis[right]] = 1

    print(result)

if __name__ == "__main__":
    main()
