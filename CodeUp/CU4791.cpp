#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
bool can_be_caught(int x,int y,int spot,int l){
    return l>=abs(x-spot)+y;
}
int main() {
    int m,n,l,temp,temp2,ans=0;
    scanf("%d %d %d",&m,&n,&l);
    vector<int> spots;
    for(int i=0;i<m;i++){
        scanf("%d ",&temp);
        spots.push_back(temp);
    }
    sort(spots.begin(),spots.end());
    for(int i=0;i<n;i++){
        scanf("%d %d",&temp,&temp2);
        int idx=lower_bound(spots.begin(),spots.end(),temp)-spots.begin();
        bool b=false;
        if(idx!=0){
            b|=can_be_caught(temp,temp2,spots[idx-1],l);
        }
        b|=can_be_caught(temp,temp2,spots[idx],l);
        if(idx<m){
            b|=can_be_caught(temp,temp2,spots[idx+1],l);
        }
        if(b){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
//사냥꾼
