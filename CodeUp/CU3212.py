import sys
from collections import deque
import heapq
input=sys.stdin.readline
v,n=map(int,input().rstrip().split())
d={i:[] for i in range(1,v+1)}
in_degree=[0 for _ in range(v)]
for _ in range(n):
    a,b=map(int,input().rstrip().split())
    d[a].append(b)
    in_degree[b-1]+=1
for i in range(1,v+1):
    d[i].sort()
start=-1
for i in range(v):
    if(in_degree[i]==0):
        start=i+1
        break
if(start==-1):
    print(-1)
else:
    ans=[]
    q=[]
    heapq.heappush(q,start)
    visited=set([start])
    while q:
        k=heapq.heappop(q)
        for i in d[k]:
            in_degree[i-1]-=1
            if(in_degree[i-1]==0):
                heapq.heappush(q,i)
                visited.add(i)
        ans.append(k)
    if(len(ans)==v):
        for i in ans:
            print(i)
    else:
        print(-1)
#나름대로 어렵지 않았다.
#처음엔 DFS로 구현하려고 했지만 제대로 되지 않아서 BFS로 갈아탔고, 배우니까 10분만에 금방 풀었다.
#위상 정렬
