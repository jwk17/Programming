n=int(input())
rgb=[list(map(int,input().split())) for _ in range(n)]
ans=100000000
def recur(last,s,idx):
    global n,rgb,ans
    if(idx==n):
        ans=min(s,ans)
        return
    if(last!="R"): recur("R",s+rgb[idx][0],idx+1)
    if(last!="G"): recur("G",s+rgb[idx][1],idx+1)
    if(last!="B"): recur("B",s+rgb[idx][2],idx+1)
recur("",0,0)
print(ans)
#RGB 거리(Small)
