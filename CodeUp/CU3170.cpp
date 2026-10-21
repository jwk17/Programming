#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    int n,m;
    map<string,int> M;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string name;
        int num;
        cin>>name>>num;
        if(M.find(name)!=M.end()){
            M[name]+=num;
        }
        else{
            M.insert({name,num});
        }
    }
    for(int i=0;i<m;i++){
        string name;
        cin>>name;
        if(M.find(name)!=M.end()){
            cout<<M[name]<<endl;
        }
        else{
            cout<<'0'<<endl;
        }
    }
    return 0;
}//기억력 테스트 9
