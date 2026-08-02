from collections import defaultdict
n=int(input())
dp=defaultdict(int)
dp[0]=1
for i in range(n):
    dp[i+1]+=dp[i]
    dp[i+2]+=dp[i]
print(dp[n])
#대표적인 dp 유형
#블럭 채우기 1(Small)
