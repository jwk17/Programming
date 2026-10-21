#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main(){
    int n,codeup,koi,ans=0;
    bool used_c=false,used_k=false;
    cin>>n;
    vector<int> c,k,s;
    for(int i=0;i<n;i++){
        cin>>codeup;
        c.push_back(codeup);
    }
    for(int i=0;i<n;i++){
        cin>>koi;
        k.push_back(koi);
        s.push_back(abs(c[i]-k[i]));
    }
    for(int i=0;i<n;i++){
        if(c[i]>k[i]){
            used_c=true;
            ans+=c[i];
        }
        else{
            used_k=true;
            ans+=k[i];
        }
    }
    if(!used_c||!used_k){
        ans-=*min(s.begin(),s.end());
    }
    cout<<ans;
    return 0;
}
//codeup vs koistudy (Small)
