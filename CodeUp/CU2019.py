import math
a,b,c=map(int,input().split())
D=b**2-4*a*c
if(D==0):
    print(f"{-b/(2*a):.2f}")
elif(D>0):
    print(f"{-b/(2*a)+math.sqrt(D)/(2*a):.2f}")
    print(f"{-b/(2*a)-math.sqrt(D)/(2*a):.2f}")
else:
    print(f"{-b/(2*a):.2f}+{math.sqrt(-D)/(2*abs(a)):.2f}i")
    print(f"{-b/(2*a):.2f}-{math.sqrt(-D)/(2*abs(a)):.2f}i")
#근의 공식만 알고 있으면 간단히 풀 수 있는 문제
#이차 방정식의 해
