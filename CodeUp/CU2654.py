n=int(input())
a,b=1,1
mod=1000000007
for _ in range(n):
	a,b=(a+b)%mod,a%mod
print(a)
#개수는 피보나치다.
