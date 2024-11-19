c=['c=','c-','dz=','d-','lj','nj','s=','z=']
w=input()
for i in c:
    w=w.replace(i,'#')
print(len(w))