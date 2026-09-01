#include <iostream>
#include <vector>
using namespace std;
int recur(vector<int> &v,int idx){
    if(idx==0||idx==1) return 1;
    if(v[idx]!=-1) return v[idx];
    int r=(recur(v,idx-2)+recur(v,idx-1));
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
//계단 오르기 1
