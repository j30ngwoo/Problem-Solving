import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n, a, b = int(input()), list(map(int, input().split())), list(map(int, input().split()))

    origin_count = 0
    for i in range(n):
        if a[i] == b[i]:
            origin_count += 1
    
    results = [0] * (n + 1)

    # 홀수
    for mid in range(n):
        count = origin_count
        l = r = mid
        while 0 <= l and r < n:
            if a[l] == b[l] and a[r] != b[l]:
                count -= 1
            elif a[l] != b[l] and a[r] == b[l]:
                count += 1
            if a[r] == b[r] and a[l] != b[r]:
                count -= 1
            elif a[r] != b[r] and a[l] == b[r]:
                count += 1
            results[count] += 1
            l, r = l - 1, r + 1

    # 짝수
    for mid in range(n - 1):
        count = origin_count
        l = mid
        r = mid + 1
        while 0 <= l and r < n:
            if a[l] == b[l] and a[r] != b[l]:
                count -= 1
            elif a[l] != b[l] and a[r] == b[l]:
                count += 1
            if a[r] == b[r] and a[l] != b[r]:
                count -= 1
            elif a[r] != b[r] and a[l] == b[r]:
                count += 1
            results[count] += 1
            l, r = l - 1, r + 1

    for result in results:
        print(result)

main()