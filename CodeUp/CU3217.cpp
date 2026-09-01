#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
const int INF=1<<30;
pair<int,int> dijkstra(vector<vector<pair<int,int>>> &graph,int n,int c){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n,INF);
    dist[c-1]=0;
    pq.push({0,c-1});
    while(!pq.empty()){
        auto [d,idx]=pq.top();
        pq.pop();
        if(d!=dist[idx]){
            continue;
        }
        for(auto[next,cost]:graph[idx]){
            int newD=d+cost;
            if(newD<dist[next]){
                dist[next]=newD;
                pq.push({newD,next});
            }
        }
    }
    int cnt=0,maxTime=0;
    for(int d:dist){
        if(d!=INF){
            cnt++;
            maxTime=max(maxTime,d);
        }
    }
    return {cnt,maxTime};
}
int main() {
    int t,n,d,c,a,b,s;
    cin>>t;
    for(int i=0;i<t;i++){
        scanf("%d %d %d",&n,&d,&c);
        vector<vector<pair<int,int>>> graph(n);
        for(int temp=0;temp<d;temp++){
            scanf("%d %d %d",&a,&b,&s);
            graph[b-1].push_back({a-1,s});
        }
        pair<int,int> ans;
        ans=dijkstra(graph,n,c);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}
//그냥 dijkstra 구현만 하면 된다.
//망가진 부품
