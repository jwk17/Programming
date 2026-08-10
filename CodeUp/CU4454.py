import heapq
n=int(input())
a,b=map(int,input().split())
kp={i:[] for i in range(1,n+1)}
for _ in range(int(input())):
    x,y=map(int,input().split())
    kp[x].append(y)
    kp[y].append(x)
l=[float('inf') for _ in range(n)]
pq=[]
heapq.heappush(pq,(0,a))
while pq:
    d,c=heapq.heappop(pq)
    if(d>l[c-1]):
        continue
    for i in kp[c]:
        if(l[i-1]>d+1):
            l[i-1]=d+1
            heapq.heappush(pq,(d+1,i))
if(100<l[b-1]):
    print(-1)
else:
    print(l[b-1])
#처음엔 BFS로 풀려다가 메모리 초과 맞고 그냥 다익스트라로 풀었다.
#촌수 계산
