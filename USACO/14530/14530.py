def find_distance(a, b):
	if a > b:
		return a - b
	else:
		return b - a

x, y = map(int, input().split())
if (x == y):
	print(0)
	exit(0)
prev_farmer = x
distance = 0
next_move = 1
while True:
	now_farmer = x + next_move
	if (x < y and now_farmer >= y or x > y and now_farmer <= y):
		distance += find_distance(prev_farmer, y)
		break
	distance += find_distance(prev_farmer, now_farmer)
	prev_farmer = now_farmer
	next_move *= -2
print(distance)