#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
int main() {
    int n,k,temp;
    cin>>n>>k;
    vector<int> coin;
    vector<int> dp(n+1,10001);
    dp[0]=0;
    for (int i=0;i<k;i++){
        cin>>temp;
        coin.push_back(temp);
    }
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
//거스름돈 II
