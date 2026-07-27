from math import factorial
n=int(input())
k=int(input())
l=list(map(int,input().split()))
def hmg(n,r):#중복조합
    return factorial(n+r-1)//factorial(r)//factorial(n-1)
print(hmg(k+1,n-sum(l)-k+1))
#요즘 복습하고 있는 중복 조합으로 쉽게 풀었다.
