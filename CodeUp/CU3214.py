import sys
input=sys.stdin.readline
n=int(input().rstrip())
l=list(map(int,input().rstrip().split()))
tree=[0 for _ in range(300000)]
for i in range(len(l)):
    tree[i+131072]=l[i]
for i in range(131071,0,-1):
    tree[i]=tree[i*2]+tree[i*2+1]
m,k=map(int,input().rstrip().split())
def sum_tree(l,r):
    l,r,ans=l+131071,r+131071,0
    while(l<=r):
        if(l%2==1):
            ans+=tree[l]
            l+=1
        if(r%2==0):
            ans+=tree[r]
            r-=1
        l,r=l//2,r//2
    return ans
def mod_tree(idx,k):
    cur,prev,idx=k,tree[idx+131071],idx+131071
    while(idx>=1):
        tree[idx]+=cur-prev
        idx//=2
for _ in range(m+k):
    x,a,b=map(int,input().rstrip().split())
    if(x==0):
        mod_tree(a,b)
    else:
        print(sum_tree(a,b))
#기억력 테스트 10
