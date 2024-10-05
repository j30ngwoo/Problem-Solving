score = {'A+':4.5,'A0':4.0,'B+':3.5,'B0':3.0,'C+':2.5,'C0':2.0,'D+':1.5,'D0':1.0,'F':0.0}

total_time = 0
s = 0
for _ in range(20):
	name, time, grade = input().split()
	if grade == 'P':
		continue
	total_time += float(time)
	s += float(time) * score[grade]
print(s / total_time)