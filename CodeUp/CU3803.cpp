#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dp[1100][4];
    int arr[1100][4];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int r,g,b;
        cin>>r>>g>>b;
        arr[i][0]=r;
        arr[i][1]=g;
        arr[i][2]=b;
    }
    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];
    for(int i=1;i<n;i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+arr[i][0];
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+arr[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+arr[i][2];
    }
    cout<<min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
    return 0;
}
//RGB거리
