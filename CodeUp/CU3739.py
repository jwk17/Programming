n=int(input())
l=[n]
idx=0
max_n=n
max_idx=0
while True:
    if(l[-1]%3==0):
        new=l[-1]//3
    elif(l[-1]%3==1):
        new=l[-1]*5-2
    else:
        new=l[-1]*5-1
    if(new>max_n):
        max_idx=idx+2
        max_n=new
    l.append(new)
    if(new==1):
        break
    idx+=1
print(idx+2)
print(max_idx,max_n)
#5n-p (Large)
