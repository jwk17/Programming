#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

void is_ranked(int idx,int cows,int &ans,std::vector<std::vector<int>> &win,std::vector<std::vector<int>> &lose){
    std::set<int> v;
    int cnt=0;
    std::queue<int> q;
    q.push(idx);
    v.insert(idx);
    while (!q.empty()){
        int i=q.front();
        q.pop();
        v.insert(i);
        for(int won:win[i]){
            if(v.find(won)==v.end()){
                v.insert(won);
                q.push(won);
                cnt++;
            }
        }
    }
    std::queue<int> sq;
    sq.push(idx);
    std::set<int> sv;
    sv.insert(idx);
    while(!sq.empty()){
        int i=sq.front();
        sq.pop();
        sv.insert(i);
        for(int lost:lose[i]){
            if(sv.find(lost)==sv.end()){
                sv.insert(lost);
                sq.push(lost);
                cnt++;
            }
        }
    }
    if(cnt==cows-1){
        ans++;
    }
}

int main() {
    int n,m;
    std::cin>>n>>m;
    std::vector<std::vector<int>> win(n,std::vector<int>(0));
    std::vector<std::vector<int>> lose(n,std::vector<int>(0));
    int a,b,ans=0;
    for(int i=0;i<m;i++){
        std::cin>>a>>b;
        win[a-1].push_back(b-1);
        lose[b-1].push_back(a-1);
    }
    for(int i=0;i<n;i++){
        is_ranked(i,n,ans,win,lose);
    }
    std::cout<<ans;
    return 0;
}
//저울의 코드를 cpp로 전환만 한 느낌
//소들의 코딩 대회
