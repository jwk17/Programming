a,b=map(int,input().split())
for i in range(a,b+1):
    t=str(i)
    cnt=t.count("3")+t.count("6")+t.count("9")
    print(t if cnt==0 else "K"*cnt)
#369 게임 2
