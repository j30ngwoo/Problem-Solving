import sys
input = lambda: sys.stdin.readline().strip()

def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = sorted(A)

    result = []
    for i in range(N):
        B_index = B.index(A[i])
        result.append(B_index)
        B[B_index] = None
    
    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()
