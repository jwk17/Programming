n=int(input())
t=list(input().split())
ansl=[]
def recur(n,l):
	global ansl,t
	if(len(l)==n+1):
		ansl.append("".join(list(map(str,l))))
		return
	if(l):
		if(t[len(l)-1]=="<"):
			for i in range(l[-1]+1,10):
				if(i not in l):
					recur(n,l+[i])
		if(t[len(l)-1]==">"):
			for i in range(l[-1]):
				if(i not in l):
					recur(n,l+[i])
	else:
		for i in range(10):
			recur(n,[i])
recur(n,[])
ansl.sort()
print(ansl[-1])
print(ansl[0])
#그냥 1~9까지 아무거나 다 넣어보면서 시도하면 되기는 하지만 너무 오래걸리니 부등호 방향이 <라면 더 큰걸로만, >면 더 작은걸로만
#재귀를 시키면 시간 초과 없이 성공할 수 있다.
#부등호
