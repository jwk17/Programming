n=int(input())
def recur(t,idx):
	if(idx==n):
		print(t)
	else:
		recur(t+"O",idx+1)
		recur(t+"X",idx+1)
recur("",0)
#가능한 경우의 수는 2**n가지이다.
#동아리 회장 선거
