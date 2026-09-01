n,m=int(input()),int(input())
prev={i:[] for i in range(1,n+1)}
subs={i:[] for i in range(1,n+1)}
ans=0
for _ in range(m):
    a,b=map(int,input().split())
    subs[a].append(b)
    prev[b].append(a)
def search(n,cnt):
    prev_c,subs_c=0,0
    v=set([n])
    s=[n]
    while s:#previous
        k=s.pop()
        v.add(k)
        for i in prev[k]:
            if(i not in v):
                v.add(i)
                s.append(i)
                prev_c+=1
    v=set([n])
    s=[n]
    while s:#subsequent
        k=s.pop()
        v.add(k)
        for i in subs[k]:
            if(i not in v):
                v.add(i)
                s.append(i)
                subs_c+=1
    return cnt-1-prev_c-subs_c
for i in range(1,n+1):
    print(search(i,n))
#전에 풀었던 키 순서? 코드를 그대로 썼다.
#저울
