n=int(input())
l=[]
start=-1
ans=1
last_flower=-1
max_end=-1
def find(idx):
    ans=-1
    ma=-1
    for i in range(idx+1,n):
        if(l[idx][1]<l[i][0]):
            return ma
        else:
            if(ans<l[i][1]):
                ans=l[i][1]
                ma=i
    return ma
for i in range(n):
    sm,sd,em,ed=map(int,input().split())
    l.append((sm*100+sd,em*100+ed))
    if(sm*100+sd<=301):
        if(start<em*100+ed):
            start=em*100+ed
    max_end=max(max_end,em*100+ed)
# l=sorted(l,key=lambda x: (x[0],-x[1]))
l.sort()
if(start!=-1):
    for i in range(n):
        if(l[i][1]==start):
            last_flower=i
            break
if(start==-1 or max_end<1131 or last_flower==-1):
    print(0)
elif(start>=1131):
    print(1)
else:
    while True:
        if(l[last_flower][1]>=1131):
            print(ans)
            break
        ans+=1
        lf=find(last_flower)
        if(lf==last_flower or lf==-1):
            print(0)
            break
        else:
            last_flower=lf
#상당히 고전했던 문제다.
#한 1~2시간은 쓴 듯..하다.
#공주님의 정원
