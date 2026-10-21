#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ANS=0;
void recur(int idx,int n,vector<int> &c,vector<int> &k,bool used_c,bool used_k,int rate){
    if(idx==n){
        if(used_c&&used_k){
            ANS=max(ANS,rate);
        }
        return;
    }
    recur(idx+1,n,c,k,true,used_k,rate+c[idx]);
    recur(idx+1,n,c,k,used_c,true,rate+k[idx]);
}
int main(){
    int n,codeup,koi;
    cin>>n;
    vector<int> c,k;
    for(int i=0;i<n;i++){
        cin>>codeup;
        c.push_back(codeup);
    }
    for(int i=0;i<n;i++){
        cin>>koi;
        k.push_back(koi);
    }
    recur(0,n,c,k,false,false,0);
    cout<<ANS;
    return 0;
}
//codeup vs koistudy (Tiny)
