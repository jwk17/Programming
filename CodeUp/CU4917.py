n=int(input())
ans=0
for i in range(1,n+1):
    t=str(i)
    for c in t:
        if(c in ["3","6","9"]):
            ans+=1
print(ans)
#369
