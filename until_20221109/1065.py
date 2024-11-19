a=int(input())
c=99
if a<=99:
    print(a)
else:
    for i in range(100,a+1):
        if (i//100-((i%100)//10)==((i%100)//10)-(i%10)):
            c+=1
    print(c)