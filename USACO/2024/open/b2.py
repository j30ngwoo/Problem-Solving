import sys
input = lambda: sys.stdin.readline().strip()

X = 0
Y = 1

n, p = map(int, input().split())
piles = []
for _ in range(p):
    piles.append(tuple(map(int, input().split())))

def get_distance(a, b):
    if a[X] == b[X]:
        return abs(a[Y] - b[Y])
    else:
        return abs(a[X] - b[X])
    
def get_between_coords(a, b):
    result = []
    if a[X] == b[X]:
        if a[Y] < b[Y]:
            for i in range(a[Y], b[Y], 1):
                result.append((a[X], i))
        else:
            for i in range(a[Y], b[Y], -1):
                result.append((a[X], i))
    else:
        if a[X] < b[X]:
            for i in range(a[X], b[X], 1):
                result.append((i, a[Y]))
        else:
            for i in range(a[X], b[X], -1):
                result.append((i, a[Y]))
    return result

accum_dist = [0] * p
dict_ = dict()
for i in range(-1, p - 1):
    now_dist = get_distance(piles[i], piles[i + 1])
    accum_dist[i + 1] = accum_dist[i] + now_dist
    for coord in get_between_coords(piles[i], piles[i + 1]):
        dict_[coord] = i % p
total_dist = accum_dist[-1]

for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    start_i = dict_[(x1, y1)]
    end_i = dict_[(x2, y2)]

    if start_i == end_i:
        forward_dist = get_distance((x1, y1), (x2, y2))
    elif start_i < end_i: 
        forward_dist = abs(accum_dist[end_i] - accum_dist[start_i]) \
                        - get_distance(piles[start_i], (x1, y1)) \
                        + get_distance(piles[end_i], (x2, y2))
    else: # start_i > end_i
        forward_dist = abs(accum_dist[end_i] - accum_dist[start_i]) \
                        + get_distance(piles[start_i], (x1, y1)) \
                        - get_distance(piles[end_i], (x2, y2))
    backward_dist = total_dist - forward_dist

    print(min(forward_dist, backward_dist))
