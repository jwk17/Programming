#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n,w,wi,vi;
    cin>>n>>w;
    vector<int> dp(w+1,0);
    for(int i=0;i<n;i++){
        cin>>wi>>vi;
        for(int j=w;j>=wi;j--){
            dp[j]=max(dp[j],dp[j-wi]+vi);
        }
    }
    cout<<dp[w];
    return 0;
}
//dp를 이용해서 푸는 전형적인 배낭 문제
//0/1 배낭 문제
