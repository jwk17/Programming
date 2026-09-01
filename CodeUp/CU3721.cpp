#include <iostream>
#include <vector>
using namespace std;
int recur(vector<int> &v,int idx){
    if(idx==0) return 1;
    if(idx==2) return 3;
    if(idx==4) return 11;
    if(v[idx]!=-1) return v[idx];
    int r=(recur(v,idx-4)*-1+recur(v,idx-2)*4)%100007;
    if(r<0){
        r+=100007;
    }
    v[idx]=r;
    return r;
}
int main() {
    int n;
    cin>>n;
    if(n%2==1) cout<<0;
    else{
        vector<int> v(n+1,-1);
        cout<<recur(v,n);
    }
    return 0;
}
//블럭 채우기 7
