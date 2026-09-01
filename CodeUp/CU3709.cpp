#include <iostream>
#include <vector>
using namespace std;
int recur(vector<int> &v,int idx){
    if(idx==0 or idx==1) return 1;
    if(idx==2) return 2;
    if(v[idx]!=-1) return v[idx];
    int r=(recur(v,idx-1)+recur(v,idx-2))%100000007;
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
//이걸로 3506번도 똑같이 풀 수 있다.
//블럭 채우기 1
