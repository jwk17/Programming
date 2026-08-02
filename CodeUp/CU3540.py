n=int(input())
ans_l=[]
def calc(t):
	l=[]
	for i in range(n-1):
		if(l and type(l[-1])==int):
			l[-1]=l[-1]*10+i+1
		else:
			l.append(i+1)
		if(t[i]!=" "):
			l.append(t[i])
	if(l and type(l[-1])==int):
		l[-1]=l[-1]*10+n
	else:
		l.append(n)
	ans=l.pop(0)
	is_plus=True
	for i in range(len(l)):
		if(type(l[i])==int):
			if(is_plus):
				ans+=l[i]
			else:
				ans-=l[i]
		else:
			if(l[i]=="+"):
				is_plus=True
			else:
				is_plus=False
	return ans
def recur(t):
	global ans_l,n
	if(len(t)==n-1):
		ans=calc(t)
		if(ans==0):
			ans_t=""
			for i in range(n-1):
				ans_t=ans_t+str(i+1)+t[i]
			ans_t=ans_t+str(n)
			ans_l.append(ans_t)
		return
	recur(t+" ")
	recur(t+"+")
	recur(t+"-")
recur("")
for i in ans_l:
	print(i)
#뭔가 복잡해 보이지만 실제로도 복잡하다.
#연산 기호가 공백이라면 마지막 숫자에 뒷 숫자를 붙이는 식으로 연산을 하도록 했다.
#0 만들기 게임
