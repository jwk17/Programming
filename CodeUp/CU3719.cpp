#include <iostream>
#include <vector>
using namespace std;
int recur(vector<int> &v,int idx){
    if(v[idx]!=-1) return v[idx];
    int r=(recur(v,idx-1)*3+recur(v,idx-2)-recur(v,idx-3)+100007)%100007;
    v[idx]=r;
    return r;
}
int main() {
    int n;
    cin>>n;
    vector<int> v(n+1,-1);
    v[1]=2;
    v[2]=7;
    v[3]=22;
    cout<<recur(v,n);
    return 0;
}
//블럭 채우기 6
