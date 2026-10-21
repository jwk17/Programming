n,c=int(input()),list(map(int,input().split()))
ans=0
def find_idx_non_zero(start_idx):
    for i in range(start_idx+1,len(c)):
        if(c[i]!=0):
            return i
    return -1
    
if(sum(c)==0):
    print(n//2)
else:
    c.extend(c)
    i=find_idx_non_zero(-1)
    while(i<n):
        if(c[i]!=0):
            idx=find_idx_non_zero(i)
            ans+=(idx-i)//2+c[i]
        i=idx
    print(ans)
#호숫가의 개미굴
