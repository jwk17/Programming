from collections import deque
n,k=map(int,input().split())
l=[input() for _ in range(n)]
d={l[i-1]:i for i in range(1,n+1)}
a,b=map(int,input().split())
def backtrack(parent,s,t):
	path=[t]
	x=t
	while parent.get(x,None)!=None:
		x=parent[x]
		path.append(x)
		if(x==s):
			break
	path.reverse()
	return path
def bfs(a,b):
	parent={}
	parent[a]=None
	q=deque([l[a-1]])
	visited=set([l[a-1]])
	while q:
		T=q.popleft()
		if(d[T]==b):
			return parent
		for i in range(k):
			m="1" if T[i]=="0" else "0"
			t=T[:i]+m+T[i+1:]
			if(d.get(t,None)!=None and t not in visited):
				q.append(t)
				visited.add(t)
				parent[d[t]]=d[T]
	return parent
p=bfs(a,b)
# print(p)
path=backtrack(p,a,b)
if(path[0]==a):
	print(*path)
else:
	print(-1)
#얘도 해밍 경로랑 같이 2시간을 들였다.
#경로 구하기
