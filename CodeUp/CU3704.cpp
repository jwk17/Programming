#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n+1,0);
    v[1]=1;
    v[2]=2;
    v[3]=4;
    if(n<=3){
        cout<<v[n];
    }
    else{
        for(int i=4;i<=n;i++){
            v[i]=(v[i-1]%1000+v[i-2]%1000+v[i-3]%1000)%1000;
        }
        cout<<v[n];
    }
    return 0;
}
//계단 오르기 2
