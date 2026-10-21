l=list(map(int,input().split()))
def postfix_exp(t):
    opr=[]
    postfix=[]
    temp=[l[0]]
    for i in range(len(l)-1):
        temp+=[t[i],l[i+1]]
    pr={"+":0,"-":0,"*":1,"/":1}
    for i in temp:
        if(type(i)==int):
            postfix.append(i)
        else:
            while(opr and pr[opr[-1]]>=pr[i]):
                postfix.append(opr.pop())
            opr.append(i)
    postfix+=opr[::-1]
    return postfix
def calc_postfix(pf):
    stack=[]
    for i in pf:
        if(type(i)==int):
            stack.append(i)
        else:
            a=stack.pop()
            b=stack.pop()
            if(i=="+"):
                stack.append(a+b)
            elif(i=="-"):
                stack.append(b-a)
            elif(i=="*"):
                stack.append(a*b)
            else:
                if(a!=0 and b%a==0):
                    stack.append(b//a)
                else:
                    return -1
    return stack[0]
ans=[]
def recur(t,idx):
    if(idx==3):
        text=""
        for i in range(3):
            text+=str(l[i])+t[i]
        text+=str(l[3])
        n=calc_postfix(postfix_exp(t))
        if(n==24):
            ans.append(text)
    else:
        recur(t+["+"],idx+1)
        recur(t+["-"],idx+1)
        recur(t+["*"],idx+1)
        recur(t+["/"],idx+1)
recur([],0)
if(not ans):
    print("Doesn't Exist")
else:
    for i in ans:
        print(i)
#중국인 게임 2
