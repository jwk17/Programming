import sys
input=sys.stdin.readline
k,n=map(int,input().rstrip().split())
lad=[]
for _ in range(n):
    a,b=map(int,input().rstrip().split())
    lad.append((a,b))
p=int(input().rstrip())
for fr,to in lad:
    go=False
    whereFr=False
    if(to==p):
        whereFr=True
        go=True
    elif(fr==p):
        whereFr=False
        go=True
    if(go):
        p=fr if whereFr else to
print(p)
#사다리 게임
