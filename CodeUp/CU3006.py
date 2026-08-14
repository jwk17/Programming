for i in range(int(input())):
    n=int(input())
    gap=2000001000
    low=0
    high=gap
    while low<high:
        mid=(low+high)//2
        if(mid*mid>n):
            high=mid
        else:
            low=mid+1
    print((low-1)**2)
#이분 탐색을 이용했다.
#완전 제곱수 찾기
