l=[]
for i in range(10000):
    l.append(i+1)
for i in range(1,10):
    a=i+i
    if l.count(a)==1:
        l.remove(a)
for i in range(10,100):
    a=i+i//10+i%10
    if l.count(a)==1:
        l.remove(a)
for i in range(100,1000):
    a=i+(i//100)+((i%100)//10)+(i%10)
    if l.count(a)==1:
        l.remove(a)
for i in range(1000,10000):
    a=i+(i//1000)+((i%1000)//100)+((i%100)//10)+(i%10)
    if l.count(a)==1:
        l.remove(a)

for i in l:
    print(i)