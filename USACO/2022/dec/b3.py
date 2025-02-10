import sys
input = lambda: sys.stdin.readline().strip()

INPUT = 0
OUTPUT = 1

def main():
    t = int(input())
    for _ in range(t):
        input()  # 빈 줄 무시
        n, m = map(int, input().split())
        cases = set()
        for _ in range(m):
            cases.add(tuple(input().split()))

        def check_all_cases():
            nonlocal cases

            for i in range(n):
                for v in ('0', '1'):
                    selected_cases = [] 
                    other_cases = []

                    for case in cases:
                        if case[INPUT][i] == v:
                            selected_cases.append(case)
                        else:
                            other_cases.append(case)

                    if selected_cases and all(case[OUTPUT] == selected_cases[0][OUTPUT] for case in selected_cases):
                        cases = set(other_cases)
                        return True
            return False

        while cases:
            if not check_all_cases():
                print('LIE')
                break
        else:
            print('OK')

if __name__ == "__main__":
    main()