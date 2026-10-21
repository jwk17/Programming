import sys
import math
input=sys.stdin.readline
n=int(input().rstrip())
l=[]
for _ in range(n):
    x,y=map(int,input().rstrip().split())
    l.append((x,y))
l.sort()
def min_dist(left,right):
    ans=400000
    for i in range(left,right):
        for j in range(i+1,right+1):
            ans=min(ans,math.sqrt((l[i][0]-l[j][0])**2+(l[i][1]-l[j][1])**2))
    return round(ans,1)
def border_min_dist(left,right):
    border=(left+right)//2
    ans=400000
    for i in range(left,border+1):
        for j in range(border+1,right+1):
            ans=min(ans,math.sqrt((l[i][0]-l[j][0])**2+(l[i][1]-l[j][1])**2))
    return round(ans,1)
def recur(left,right):
    if(right-left+1>16):
        k=(right-left)//2
        a=recur(left,k+left)
        b=recur(k+left+1,right)
        return min(a,b)
    else:
        return min(min_dist(left,right),border_min_dist(left,right))
print(recur(0,n-1))
#가장 가까운 두 점의 거리(Large)
