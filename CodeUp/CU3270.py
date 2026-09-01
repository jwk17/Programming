n,m=map(int,input().split())
parent=[i for i in range(n+1)]
def find(n):
    if(n==parent[n]):
        return n
    parent[n] = find(parent[n])
    return find(parent[n])
def union(a,b):
    root_a,root_b=find(a),find(b)
    if(root_a!=root_b):
        if(root_a<root_b):
            parent[root_b]=root_a
        else:
            parent[root_a]=root_b
for _ in range(m):
    a,b=map(int,input().split())
    union(a,b) 
for i in range(1,n+1):
    print(find(i),end=" ")
//union-find를 구현하면 된다.
//중립국 1
