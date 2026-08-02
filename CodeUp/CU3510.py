n=int(input())
k=int(input())
l=list(map(int,input().split()))
ans=0
def recur(s,idx):
    global l,n,k,ans
    if(idx==k):
        if(s<=n):
            ans=max(ans,s)
        return
    recur(s+l[idx],idx+1)
    recur(s,idx+1)
recur(0,0)
print(ans)
#여기서 7줄 앞에 if(s>n):return 을 넣는다면 더 빠르게 작동할 것 같다.
#예산 관리
