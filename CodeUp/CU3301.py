n=int(input())
l=[10,50,100,500,1000,5000,10000,50000]
ans=0
for i in l[::-1]:
    ans+=n//i
    n-=(n//i)*i
print(ans)
#거스름돈
