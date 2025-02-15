AZ = "abcdefghijklmnopqrstuvwxyz"

def main():
    n, f = map(int, input().split())
    s = input()
    moos = {a + b + b:[] for a in AZ for b in AZ if a != b}
    possibles = {a + b + b:[] for a in AZ for b in AZ if a != b}
    for i in range(n - 2):
        if s[i] != s[i + 1] == s[i + 2]:
            moos[s[i:(i + 3)]].append(i)
        for change in range(3):
            for new_alpha in AZ:
                moo = list(s[i:(i + 3)])
                moo[change] = new_alpha
                moo = ''.join(moo)
                if moo[0] != moo[1] == moo[2]:
                    if len(possibles[moo]) < 2:
                        possibles[moo].append(i)
                    else:
                        possibles[moo][1] = i

    result = []
    for moo, idxs in moos.items():
        if len(idxs) >= f:
            result.append(moo)
        elif len(idxs) + 1 == f and possibles[moo]:
            if f == 1:
                result.append(moo)
            elif possibles[moo][0] <= idxs[0] - 3 or idxs[-1] + 3 <= possibles[moo][1]:
                result.append(moo)

    print(len(result))
    if result:
        print('\n'.join(result))

main()