n=int(input())
t=list(map(int,input().split()))+[0 for _ in range(65536)]
tree=[0 for _ in range(200000)]
for i in range(65536):
    tree[i+65536]=t[i]
for i in range(131071,1,-1):
    tree[i//2]=max(tree[i//2],tree[i])
def max_tree(l,r):
    l,r,ans=l+65535,r+65535,0
    while(l<=r):
        if(l%2==1):
            ans=max(tree[l],ans)
            l+=1
        if(r%2==0):
            ans=max(tree[r],ans)
            r-=1
        l,r=l//2,r//2
    return ans
m=int(input())
for _ in range(m):
    a,b=map(int,input().split())
    print(max_tree(a,b),end=" ")
#기억력 테스트 5
