import sys
input = lambda: sys.stdin.readline().strip()

def main():
    N = int(input())
    S = input()
    
    dict_ = dict()
    for i in range(N):
        if N % 2 == 1 and N // 2 == i:
            continue
        if dict_.get(S[i]):
            dict_[S[i]] += 1
        else:
            dict_[S[i]] = 1

    if all(v % 2 == 0 for v in dict_.values()):
        print('Yes')
    else:
        print('No')

if __name__ == "__main__":
    main()
