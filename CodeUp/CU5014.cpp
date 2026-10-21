#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
bool b[120][120];
vector<vector<bool>> filled(120,vector<bool>(120,true));
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x,y,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        b[x][y]=true;
    }
    set<pair<int,int>> v;
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        pair<int,int> pos=q.front();
        q.pop();
        v.insert(pos);
        filled[pos.first][pos.second]=false;
        for(int i=0;i<4;i++){
            int nx=pos.first+dx[i],ny=pos.second+dy[i];
            if(0<=nx&&nx<=101&&0<=ny&&ny<=101&&!b[ny][nx]&&v.find(make_pair(nx,ny))==v.end()){
                q.push(make_pair(nx,ny));
                v.insert(make_pair(nx,ny));
            }
        }
    }
    int answer=0;
    for(int x=0;x<101;x++){
        for(int y=0;y<101;y++){
            if(filled[y][x]){            
                for(int dir=0;dir<4;dir++){
                    if(!filled[y+dy[dir]][x+dx[dir]]){
                        answer++;
                    }
                }
            }
        }
    }
    cout<<answer;
    return 0;
}
//둘레 (Bronze)
