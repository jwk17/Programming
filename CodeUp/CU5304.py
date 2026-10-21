n=int(input())
a=[list(map(int,input().split())) for _ in range(n)]
b=[list(map(int,input().split())) for _ in range(n)]
def rotate():
    l=[]
    a_flip=[]
    rotate1=[]
    rotate1_flip=[]
    for i in range(n):
        temp=[]
        a_flip.append(a[i][::-1])
        for j in range(i,n):
            temp.append(a[j][i])
        rotate1.append(temp)
        rotate1_flip.append(temp[::-1])
    rotate1=rotate1[::-1]
    l.append(a)
    l.append(a_flip)
    l.append(rotate1)
    l.append(rotate1_flip[::-1])
    rotate2=[]
    rotate2_flip=[]
    for i in range(n,0,-1):
        temp=[]
        for j in range(i):
            temp.append(a[j+n-i][j])
        rotate2.append(temp[::-1])
        rotate2_flip.append(temp)
    rotate2=rotate2[::-1]
    l.append(rotate2)
    l.append(rotate2_flip[::-1])
    return l
def diff(a,b):
    d=0
    for i in range(n):
        for j in range(i+1):
            d+=1 if a[i][j]!=b[i][j] else 0
    return d
r=rotate()
ans=1000
for i in r:
    ans=min(ans,diff(i,b))
print(ans)
#두 정삼각형
