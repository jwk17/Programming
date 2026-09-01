n=int(input())
t=str(n)
num="영일이삼사오육칠팔구"
ans=""
if(n==0):
    print("영")
else:
    if(t[-1]!="0"):
        ans=num[int(t[-1])]+ans
    if(n>=10 and t[-2]!="0"):
        ans=num[int(t[-2])]+"십"+ans
    if(n>=100 and t[-3]!="0"):
        ans=num[int(t[-3])]+"백"+ans
    if(n>=1000 and t[-4]!="0"):
        ans=num[int(t[-4])]+"천"+ans
    if(n>=10000):
        tk_check=t[:-4]
        if(len(tk_check)>4):
            tk_check=tk_check[-4:]
        if(not tk_check=="0000" or tk_check=="000" or tk_check=="00" or tk_check=="0"):
            ans="만"+ans
        if(t[-5]!="0"):
            ans=num[int(t[-5])]+ans
    if(n>=100000 and t[-6]!="0"):
        ans=num[int(t[-6])]+"십"+ans
    if(n>=1000000 and t[-7]!="0"):
        ans=num[int(t[-7])]+"백"+ans
    if(n>=10000000 and t[-8]!="0"):
        ans=num[int(t[-8])]+"천"+ans
    if(n>=100000000):
        ans="억"+ans
    if(n>=100000000 and t[-9]!="0"):
        ans=num[int(t[-9])]+ans
    if(n>=1000000000 and t[-10]!="0"):
        ans=num[int(t[-10])]+"십"+ans
    print(ans)
#숫자를 한글로 변환
