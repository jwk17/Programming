#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main() {
    int n,m,temp;
    cin>>n;
    vector<pair<int,int>> k(n);
    for(int i=0;i<n;i++){
        cin>>temp;
        k[i]={temp,i};
    }
    cin>>m;
    sort(k.begin(),k.end());
    for(int i=0;i<m;i++){
        cin>>temp;
        auto it=lower_bound(k.begin(),k.end(),make_pair(temp,0));
        if(it!=k.end()&&it->first==temp){
            cout<<it->second +1<<" ";
        }
        else{
            cout<<"-1 ";
        }
    }
    return 0;
}
//기억력 테스트 4
