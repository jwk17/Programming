n=input()
ans=0
for c in n:
    d=int(c)
    if(d>=3):
        d-=1
    ans=ans*9+d
print(ans)
#3이 없는 나라
