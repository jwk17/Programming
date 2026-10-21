#include <iostream>
#include <vector>

using namespace std;
int ans=0,n,k;
bool check_if_right(vector<bool> &v){
    if(v.size()==n){
        for(int i=1;i<n-1;i++){
            if(v[i]){
                if(v[i-1]&&v[i+1]){return false;}
            }
        }
        if(v.size()>1){        
            if(v[0]&&v[1]){return false;}
            if(v[n-1]&&v[n-2]){return false;}
        }
        
    }
    else{
        for(int i=1;i<v.size()-1;i++){
            if(v[i]){
                if(v[i-1]&&v[i+1]){return false;}
            }
        }
        if(v.size()>1){
            if(v[0]&&v[1]){return false;}
        }
    }
    return true;
}
void recur(vector<bool> &v,int p){
    if(p==k){
        // for(bool i:v){
        //     cout<<(i?1:0)<<' ';
        // }
        // for(int i=0;i<n-v.size();i++){
        //     cout<<0<<' ';
        // }
        // cout<<check_if_right(v);
        if(check_if_right(v)){
            ans++;
        }
        // cout<<'\n';
        return;
    }
    if(n==v.size()){
        return;
    }
    v.push_back(false);
    recur(v,p);
    v.pop_back();
    v.push_back(true);
    recur(v,p+1);
    v.pop_back();
}
int main() {
    cin>>n>>k;
    vector<bool> v={};
    if(n==1){
        cout<<1;
    }
    else{    
        recur(v,0);
        cout<<ans;
    }
    return 0;
}
//극장 좌석 배치 3
