#include <iostream>
#include <vector>
using namespace std;
int recur(vector<int> &v,int idx){
    if(idx==1) return 1;
    if(idx==2) return 5;
    if(idx==3) return 11;
    if(v[idx]!=-1) return v[idx];
    int r=(recur(v,idx-1)+recur(v,idx-2)*4+recur(v,idx-3)*2)%100007;
    v[idx]=r;
    return r;
} 
int main() {
    int n;
    cin>>n;
    vector<int> v(n+1,-1);
    cout<<recur(v,n);
    return 0;
}
//블럭 채우기 4
