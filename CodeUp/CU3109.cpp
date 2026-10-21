#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    int n,num;
    string name;
    char cmd;
    map<int,vector<string>> m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cmd>>num>>name;
        if(cmd=='I'){        
            if(m.find(num)!=m.end()){
                m[num].insert(m[num].begin(),name);
            }
            else{
                m.insert({num,{name}});
            }
        }
        else{
            if(m.find(num)!=m.end()){
                m[num].erase(m[num].begin());
            }
        }
    }
    vector<pair<int,string>> v;
    for(auto iter=m.begin();iter!=m.end();iter++){
        vector<string> temp=iter->second;
        for(string s:temp){
            v.push_back({iter->first,s});
        }
    }
    for(int i=0;i<5;i++){
        int d;
        cin>>d;
        cout<<v[d-1].first<<" "<<v[d-1].second<<endl;
    }
    return 0;
}
//정올 참여 학생 리스트 만들기 2
