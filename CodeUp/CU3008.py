l=sorted(list(int(input()) for _ in range(9)))
s=sum(l)
left,right=0,8
while left<right:
    v=l[left]+l[right]
    if(v==s-100):
        for i in range(9):
            if(i!=left and i!=right):
                print(l[i])
        break
    elif(v>s-100):
        right-=1
    else:
        left+=1
#투포인터로 풀었다.
#일곱 난쟁이
