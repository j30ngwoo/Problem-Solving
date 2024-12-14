import sys
input = lambda: sys.stdin.readline().strip()

X = 0
O = 1
XO = ['X', 'O']


def main():
    states = set()
    state = ['.'] * 9

    def is_end():
        if state[0] == state[3] == state[6] != '.':
            return True
        if state[1] == state[4] == state[7] != '.':
            return True
        if state[2] == state[5] == state[8] != '.':
            return True
        if state[0] == state[1] == state[2] != '.':
            return True
        if state[3] == state[4] == state[5] != '.':
            return True
        if state[6] == state[7] == state[8] != '.':
            return True
        if state[0] == state[4] == state[8] != '.':
            return True
        if state[2] == state[4] == state[6] != '.':
            return True
        if state[0] == state[3] == state[6] != '.':
            return True
        return False

    def recursion(prev_unit, depth):
        if depth == 9 or is_end():
            states.add(''.join(state))
            return

        now_unit = int(not prev_unit)
        for i in range(9):
            if state[i] == '.':
                state[i] = XO[now_unit]
                recursion(now_unit, depth + 1)
                state[i] = '.'

    recursion(O, 0)

    while True:
        s = input()
        if s == 'end':
            break
        
        if s in states:
            print('valid')
        else:
            print('invalid')

if __name__ == "__main__":
    main()
