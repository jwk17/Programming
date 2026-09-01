#include <iostream>
#include <vector>
using namespace std;
int recur(vector<int> &v,int idx){
    if(idx==0 or idx==1) return 1;
    if(idx==2) return 3;
    if(v[idx]!=-1) return v[idx];
    int r=(recur(v,idx-1)+recur(v,idx-2)*2)%100007;
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
//이런 문제는 점화식 찾기가 알파이자 오메가이다
//블럭 채우기 3
