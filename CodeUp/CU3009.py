ans=0
n,s=map(int,input().split())
l=list(map(int,input().split()))
def recur(v,idx):
    global ans,n,s
    if(idx==n):
        if(v==s):
            ans+=1
        return
    else:
        recur(v,idx+1)
        recur(v+l[idx],idx+1)
recur(0,0)
if(s==0):
    print(ans-1)
else:
    print(ans)
#어짜피 N<=20이라서 각각 넣기 안넣기로 반복하면 된다.
#부분수열의 합
