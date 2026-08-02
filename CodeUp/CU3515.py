n=int(input())
l=list(list(map(int,input().split())) for _ in range(n))
ans=0
def backtrack(exc,idx,s):
    global ans,n,l
    if(idx==n):
        ans=max(ans,s)
    for i in range(n):
        if(not exc[i]):
            exc[i]=True
            backtrack(exc,idx+1,s+l[idx][i])
            exc[i]=False
backtrack([False for _ in range(n)],0,0)
print(ans)
#사탕 줍기 2
