#include <iostream>
#include <vector>

using namespace std;
int INF=1<<30;
struct Edge{
    int from;
    int to;
    int weight;
};
bool bellman_ford(int start,vector<vector<Edge>> &edges,int n,int m,int w){
    vector<int> dist(n,INF);
    dist[start-1]=0;
    for(int i=0;i<n-1;i++){
        for(int i=0;i<n;i++){
            if(dist[i]==INF){
                continue;
            }
            for(Edge e:edges[i]){
                if(dist[e.to-1]>dist[i]+e.weight){
                    dist[e.to-1]=dist[i]+e.weight;
                }
            }
        }
    }
    if(dist[start-1]<0){
        return true;
    }
    return false;
}
int main() {
    int f,n,m,w,s,e,t;
    cin>>f;
    for(int test=0;test<f;test++){
        scanf("%d %d %d",&n,&m,&w);
        vector<Edge> edges(n+1);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&s,&e,&t);
            edges.push_back({s,e,t});
            edges.push_back({e,s,t});
        }
        for(int i=0;i<w;i++){
            scanf("%d %d %d",&s,&e,&t);
            edges.push_back({s,e,-t});
        }
        vector<int> dist(n,0);
        bool success=false;
        for(int i=0;i<n;i++){
            for(Edge e:edges){
                int from=e.from,to=e.to,weight=e.weight;
                if(dist[to-1]>dist[from-1]+weight){
                    dist[to-1]=dist[from-1]+weight;
                    if(i==n-1){
                        success=true;
                        break;
                    }
                }
            }
        }
        if(success)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
//벨만 포드를 사용해서 만일 음수 사이클이 있다면 성공이다.
//웜홀
