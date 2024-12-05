import sys
input = lambda: sys.stdin.readline().strip()

X = 0
Y = 1
DX = []

def main():
    n, m, l, k = map(int, input().split())
    meteros = []
    for _ in range(k):
        meteros.append(list(map(int, input().split())))

    def counting_stars(top, right, bottom, left):
        count = 0
        for coord in meteros:
            if left <= coord[X] <= right and bottom <= coord[Y] <= top:
                count += 1
        return count

    max_bounce = 0
    for coord1 in meteros:
        for coord2 in meteros:
            if coord1[X] < coord2[X] and coord1[Y] < coord2[Y]:
                max_bounce = max(
                    max_bounce,
                    counting_stars(coord1[Y] + l, coord2[X], coord1[Y], coord2[X] - l),
                    counting_stars(coord2[Y], coord1[X] + l, coord2[Y] - l, coord1[X])
                )
            elif coord1[X] > coord2[X] and coord1[Y] < coord2[Y]:
                max_bounce = max(
                    max_bounce,
                    counting_stars(coord2[Y] + l, coord1[X] + l, coord2[Y], coord1[X]),
                    counting_stars(coord1[Y], coord2[X], coord1[Y] - l, coord2[X] - l)
                )

    for coord in meteros:
        max_bounce = max(
                    max_bounce,
                    counting_stars(coord[Y] + l, coord[X] + l, coord[Y], coord[X]),
                    counting_stars(coord[Y], coord[X] + l, coord[Y] - l, coord[X]),
                    counting_stars(coord[Y], coord[X], coord[Y] - l, coord[X] - l),
                    counting_stars(coord[Y] + l, coord[X], coord[Y], coord[X] - l)
                )
    
    print(k - max_bounce)

if __name__ == "__main__":
    main()
