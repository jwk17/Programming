n=int(input())
memo=[1,1]
for _ in range(n):
	memo.append(memo[-1]+memo[-2])
print(memo[-1])
#그냥 피보나치 수열이다...
#규칙에 맞는 이진수 만들기(Small)
