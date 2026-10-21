#include <iostream>
#include <vector>

using namespace std;
int life_cnt(int w,int h,int x,int y,vector<vector<int>> &l){
    int ans=0;
    int dx[8]={-1,0,1,1,1,0,-1,-1};
    int dy[8]={-1,-1,-1,0,1,1,1,0};
    for(int i=0;i<8;i++){
        if(0<=x+dx[i]&&x+dx[i]<w&&0<=y+dy[i]&&y+dy[i]<h&&l[y+dy[i]][x+dx[i]]==1){
            ans++;
        }
    }
    return ans;
}
int main() {
    int h,w,X,Y,Z,k,temp;
    cin>>h>>w>>X>>Y>>Z;
    vector<vector<int>> l(h,vector<int>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>temp;
            l[i][j]=temp;
        }
    }
    cin>>k;
    vector<vector<int>> nl(h,vector<int>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            nl[i][j]=l[i][j];
        }
    }
    for(int i=0;i<k;i++){
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                int life=life_cnt(w,h,x,y,l);
                if(l[y][x]==1){
                    if(life>=Z ||life<Y){
                        nl[y][x]=0;
                    }
                }
                else{
                    if(life==X){
                        nl[y][x]=1;
                    }
                }
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                l[i][j]=nl[i][j];
            }
        }
    }
    for(vector<int> d:l){
        for(int dd:d){
            cout<<dd<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//생명 게임 2
