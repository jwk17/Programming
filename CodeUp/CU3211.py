n,m=map(int,input().split())
t=[0 for _ in range(65536)]
for i in range(n):
    t[i]=int(input())
tree=[(0,1000001) for _ in range(200000)]
for i in range(65536):
    tree[i+65536]=(t[i],t[i])
for i in range(131071,1,-1):
    tree[i//2]=(max(tree[i//2][0],tree[i][0]),min(tree[i//2][1],tree[i][1]))
def max_tree(l,r):
    l,r,M,m=l+65535,r+65535,0,1000001
    while(l<=r):
        if(l%2==1):
            M=max(tree[l][0],M)
            m=min(tree[l][1],m)
            l+=1
        if(r%2==0):
            M=max(tree[r][0],M)
            m=min(tree[r][1],m)
            r-=1
        l,r=l//2,r//2
    return M-m
for _ in range(m):
    a,b=map(int,input().split())
    print(max_tree(a,b))
#기억력 테스트 6
