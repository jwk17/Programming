#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x,y,r,ans=0;
    bool map[120][120]={false,};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y>>r;
        for(int j=y;j<y+r;j++){
            for(int i=x;i<x+r;i++){
                map[j+1][i+1]=true;
            }
        }
    }
    for(int i=0;i<=101;i++){
        map[i][0]=false;
        map[i][101]=false;
        map[0][i]=false;
        map[i][101]=false;
    }
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(map[j][i]){                
                for(int idx=0;idx<4;idx++){
                    if(j+dy[idx]==101||j+dy[idx]==0||i+dx[idx]==0||i+dx[idx]==101){
                        ans++;
                    }
                    else if(!map[j+dy[idx]][i+dx[idx]]&&j+dy[idx]<101&&i+dx[idx]<101&&j+dy[idx]>0&&i+dx[idx]>0){
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
//다각형의 모양
