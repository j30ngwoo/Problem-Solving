import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    t = int(input())
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    b = list(map(int, input().split()))
    
    a_table = {}
    for start in range(n):
        range_sum = 0
        for stop in range(start + 1, n + 1):
            range_sum += a[stop - 1]
            if range_sum in a_table:
                a_table[range_sum] += 1
            else:
                a_table[range_sum] = 1

    b_table = {}
    for start in range(m):
        range_sum = 0
        for stop in range(start + 1, m + 1):
            range_sum += b[stop - 1]
            if range_sum in b_table:
                b_table[range_sum] += 1
            else:
                b_table[range_sum] = 1

    a_sums, b_sums = sorted(a_table), sorted(b_table, reverse=True)
    
    result = a_index = b_index = 0
    while a_index < len(a_sums) and b_index < len(b_sums):
        s = a_sums[a_index] + b_sums[b_index]
        if s == t:
            result += a_table[a_sums[a_index]] * b_table[b_sums[b_index]]
            a_index += 1
            b_index += 1
        elif s < t:
            a_index += 1
        else:
            b_index += 1
    
    print(result)

if __name__ == "__main__":
    main()
