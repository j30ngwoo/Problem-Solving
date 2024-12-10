import sys
input = lambda: sys.stdin.readline().strip()

LOG2 = 54

def main():
    a, b = map(int, input().split())
    
    # 2^i보다 작은 모든 x의 1의 합
    prefix_sums = [0, 1]

    for i in range(1, LOG2):
        prefix_sums.append(prefix_sums[i] * 2 + 2 ** i)

    def is_power2(n):
        return n > 0 and (n & (n - 1)) == 0

    def log2(n):
        return len(bin(n)) - 3

    def get_sum(n, depth):
        if is_power2(n):
            return prefix_sums[int(log2(n))] + n * depth
        
        next_n = 2 ** int(log2(n))
        return get_sum(next_n, depth) + get_sum(n - next_n, depth + 1)

    print(get_sum(b + 1, 0) - get_sum(a, 0))

if __name__ == "__main__":
    main()
