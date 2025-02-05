import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    is_prime = [False, False] + [True] * (n - 1)
    for i in range(2, int(n ** (1 / 2) + 1)):
        for mul in range(2, n // i + 1):
            is_prime[i * mul] = False
    
    primes = []
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)

    sums = [0]
    for prime in primes:
        sums.append(sums[-1] + prime)

    def find_first(left, right):
        nonlocal last, n
        
        if left > right:
            return False

        mid = (left + right) // 2
        accum = sums[last] - sums[mid]

        if accum == n:
            return True
        
        if accum > n:
            return find_first(mid + 1, right)
        else:
            return find_first(left, mid - 1)

    result = 0
    for last in range(1, len(sums)):
        if find_first(0, last - 1):
            result += 1
    
    print(result)

if __name__ == "__main__":
    main()
