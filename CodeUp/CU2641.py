n=int(input())
memo=[(False,False,0)]
ans=0
while memo:
    b1,b2,s=memo.pop()
    if(s==n):
        ans+=1
    else:
        if(not b1 and not b2 and s+3<=n):
            memo.append((b2,True,s+3))
        if(s+2<=n):
            memo.append((b2,False,s+2))
        if(s+1<=n):
            memo.append((b2,False,s+1))
print(ans)
#다이내믹 프로그래밍에서 자주 출제되는 유형이다.
#숏다리의 계단 오르기(Small)
