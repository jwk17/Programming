import sys
n=int(input())
def check_good(t):
    n=len(t)
    for i in range(2,n//2+1):
        for si in range(0,n-2*i+1):
            if(t[si:si+i]==t[si+i:si+2*i]):
                return False
    return True
#모든 길이를 하나씩 시도해 보면서 인접하면서 같은 문자열이 있다면 안 좋은 거니 False를 리턴하고, 아니면 True를 리턴한다.
def recur(t):
    if(len(t)>=1):
        if(check_good(t)):
            if(len(t)==n):
                print(t)
                sys.exit()
            if(t[-1]!="1"):
                recur(t+"1")
            if(t[-1]!="2"):
                recur(t+"2")
            if(t[-1]!="3"):
                recur(t+"3")
    else:
        recur(t+"1")
        recur(t+"2")
        recur(t+"3")
recur("")
#그 다음은 그냥 재귀다.
#좋은 수열
