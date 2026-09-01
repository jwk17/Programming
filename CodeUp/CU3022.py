a,b=input(),input()
al,bl=list(a)[::-1],list(b)[::-1]
ansl=[]
minus=0
def is_max(a,b):
    if(len(a)>len(b)):
        return True
    elif(len(a)<len(b)):
        return False
    else:
        for i in range(len(a)-1,-1,-1):
            if(a[i]<b[i]):
                return False
            elif(a[i]>b[i]):
                return True
    return True
bigger=is_max(al,bl)
if(not bigger):
    al,bl=bl,al
#al이 더 큰거
for i in range(max(len(al),len(bl))):
    av,bv=0,0
    if(i<len(al)):av=int(al[i])
    if(i<len(bl)):bv=int(bl[i])
    s=av-bv-minus
    if(s<0):
        minus=1
        s+=10
    else:
        minus=0
    ansl.append(str(s))
for _ in range(len(ansl)):
    if(ansl[-1]=='0'):
        del ansl[-1]
    else:
        break
if(len(ansl)==0):
    print("0")
else:
    if(bigger):
        print("".join(ansl[::-1]))
    else:
        print("-"+"".join(ansl[::-1]))
#큰 수 덧셈이랑 비슷하게 구현하면 된다.
#큰 수 뺄셈
