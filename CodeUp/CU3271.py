import sys
input=sys.stdin.readline
n,m=int(input().rstrip()),int(input().rstrip())
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
    a,b=map(int,input().rstrip().split())
    union(a,b)
c=int(input().rstrip())
country={}
for _ in range(c):
    a,b=map(int,input().rstrip().split())
    country[find(a)]=b
for i in range(1,n+1):
    print(country.get(find(i),0),end=" ")
#이것도 union-find를 이용해서 구현할 수 있다.
#중립국 2
