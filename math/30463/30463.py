import sys
input = lambda: sys.stdin.readline().strip()
from math import comb

KEY = 0
VALUE = 1

def main():
    n, k = map(int, input().split())
    dict_ = dict()
    for _ in range(n):
        s = input()
        general_s = ''.join(sorted(list(set(s))))
        if general_s not in dict_:
            dict_[general_s] = 1
        else:
            dict_[general_s] += 1

    result = 0

    dict_items = list(dict_.items())
    for l in range(len(dict_items) - 1):
        for r in range(l + 1, len(dict_items)):
            if len(set(dict_items[l][KEY]) | set(dict_items[r][KEY])) == k:
                result += dict_items[l][VALUE] * dict_items[r][VALUE]

    for key, value in dict_items:
        if len(key) == k:
            result += comb(value, 2)

    print(result)

if __name__ == "__main__":
    main()
