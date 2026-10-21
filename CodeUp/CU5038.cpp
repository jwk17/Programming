#include <iostream>
#include <vector>

using namespace std;
vector b(10000050,true);
vector<int> p(int n){
    vector<int> rtn;
    for(int i=2;i<=n;i++){
        if(n%i==0){  
            rtn.push_back(i);
            while(n%i!=0){
                n/=i;
            }
        }
    }
    return rtn;
}
int main() {
    int n;
    cin>>n;
    vector<int> r=p(n);
    for(int i:r){
        int j=i;
        while(j<=n){
            b[j]=false;
            j+=i;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(b[i]){cnt++;}
    }
    cout<<cnt;
    return 0;
}//서로 소(Large)
