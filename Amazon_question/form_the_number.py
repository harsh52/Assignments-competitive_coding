x=list(input().split(","))
y=[]
count=0
for j in x:
    y.append(int(j))
    if int(j)<0:
        count+=1
res=0
for i in range(len(y)):
    res=res+ abs(y[i])*pow(10,len(y)-i-1)
if count%2==0:
    print(res)
else:
    print (res* -1)