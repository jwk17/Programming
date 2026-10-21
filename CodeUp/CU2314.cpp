#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
int main() {
    int n,k,temp;
    cin>>n;
    vector<int> coin={1,3,5,10};
    vector<int> dp(n+1,1000001);
    dp[0]=0;
    for(int i=1;i<n+1;i++){
        for(int c:coin){
            if(i>=c){
                dp[i]=min(dp[i],dp[i-c]+1);
            }
        }
    }
    cout<<dp[n];
    return 0;
}
//한라봉 포장
