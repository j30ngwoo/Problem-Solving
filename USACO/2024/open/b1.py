import sys
input = lambda: sys.stdin.readline().strip()

LEFT = 0
RIGHT = 1

n, q = map(int, input().split())
formula = input().split()

# 식의 index별로 그룹의 id를 설정
group_ids = [-1] * n
id = 0
for i in range(n):
    if formula[i] == 'or':
        id += 1
    if i % 2 == 0:
        group_ids[i] = id

# 각 그룹 내에서, 가장 왼쪽과 오른쪽에 있는 false의 위치를 기록
pos_of_false_by_group = [[float('inf'), float('-inf')] for _ in range(id + 1)]
id = 0
for i in range(n):
    if formula[i] == 'or':
        id += 1
    if formula[i] == 'false':
        if pos_of_false_by_group[id][LEFT] == float('inf'):
            pos_of_false_by_group[id][LEFT] = i
        pos_of_false_by_group[id][RIGHT] = i

# 수정하지 않을 경우 항상 true가 되는 그룹 중에 가장 왼쪽과 오른쪽에 있는 그룹을 기록
left_true_group_id = float('inf')
right_true_group_id = float('-inf')
for id in range(len(pos_of_false_by_group)):
    if pos_of_false_by_group[id] == [float('inf'), float('-inf')]:
        if left_true_group_id == float('inf'):
            left_true_group_id = id
        right_true_group_id = id

# 주요 로직
for _ in range(q):
    l, q, b = input().split()
    l, q = int(l) - 1, int(q) - 1
    l_group_id, q_group_id = group_ids[l], group_ids[q]

    if left_true_group_id < l_group_id or q_group_id < right_true_group_id:
        # 수정 가능 그룹 외에 true가 있으므로, 항상 결과값이 true가 됨.
        result = 'true'
    else: # 수정 가능 그룹 외에는 true가 없는 경우
        if pos_of_false_by_group[l_group_id][LEFT] < l or q < pos_of_false_by_group[q_group_id][RIGHT]:
            # 무엇으로 대체하든 그룹 내에 false가 남아있다. 그룹 결과값은 항상 false. 최종 결과값도 항상 false.
            result = 'false'
        else:
            # 무엇으로 대체하냐에 따라 최종 결과값은 true, false 둘 다 가능하다
            result = 'both'

    if b == result or result == 'both':
        print('Y', end='')
    else:
        print('N', end='')