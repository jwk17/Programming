ans=[]
def check(idx):
    if(idx==15):
        is_okay=True
        for i in range(6):
            if(sum(table[i])!=0):
                is_okay=False
                break
        if(is_okay):
            return 1
    else:
        a,b=l[idx]
        if(table[a][0]>0 and table[b][2]>0):
            table[a][0]-=1
            table[b][2]-=1
            if(check(idx+1)):
                return 1
            table[a][0]+=1
            table[b][2]+=1
        if(table[a][1]>0 and table[b][1]>0):
            table[a][1]-=1
            table[b][1]-=1
            if check(idx+1):
                return 1
            table[a][1]+=1
            table[b][1]+=1
        if(table[a][2]>0 and table[b][0]>0):
            table[a][2]-=1
            table[b][0]-=1
            if check(idx+1):
                return 1
            table[a][2]+=1
            table[b][0]+=1
for i in range(4):
    table={}
    inp=list(map(int,input().split()))
    for i in range(6):
        table[i]=inp[i*3:i*3+3]
    l=[(i,j) for i in range(6) for j in range(i+1,6)]
    a=check(0)
    if(a==1):
        ans.append(1)
    else:
        ans.append(0)
print(*ans)
#그냥 열심히 확인하면 된다.
#월드컵
