import sys
input=sys.stdin.readline
n=int(input().rstrip())
d={i:[] for i in range(1,n+1)}
is_basic={i:True for i in range(1,n+1)}
for _ in range(int(input().rstrip())):
    a,b,c=map(int,input().rstrip().split())
    is_basic[a]=False
    d[a].append((b,c))
basics={}
basics_count=0
for i in range(1,n+1):
    if is_basic[i]:
        basics[i]=0
        basics_count+=1
s=[(n,1)]
while s:
    a,b=s.pop()
    if(is_basic[a]):
        basics[a]+=b
    else:
        for x,y in d[a]:
            s.append((x,y*b))
print(basics_count)
for k,v in basics.items():
    print(k,v)
#그냥 나쁘지 않았던 문제
#장난감 조립
