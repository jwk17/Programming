from collections import deque
n,k=map(int,input().split())
l=[input() for _ in range(n)]
d={l[i-1]:i for i in range(1,n+1)}
m=int(input())
j=[int(input()) for _ in range(m)]
def backtrack(parent,t):
	path=[t]
	x=t
	while parent.get(x,None)!=None:
		x=parent[x]
		path.append(x)
	path.reverse()
	return path
def bfs():
	parent={}
	parent[1]=None
	q=deque([l[0]])
	visited=set([l[0]])
	while q:
		T=q.popleft()
		for i in range(k):
			m="1" if T[i]=="0" else "0"
			t=T[:i]+m+T[i+1:]
			if(d.get(t,None)!=None and t not in visited):
				q.append(t)
				visited.add(t)
				parent[d[t]]=d[T]
	return parent
p=bfs()
for i in j:
	path=backtrack(p,i)
	if(path[0]==1):
		print(*path)
	else:
		print(-1)
#이거에 2시간 가량을 썼다.
#처음으로 BFS+백트래킹으로 구현해 봤는데, 진짜 힘들었다.
#해밍 경로
