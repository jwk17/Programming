#include <iostream>
#include <vector>
#include <stack>//dfs 용
#include <queue>//우선순위 큐 용
#include <algorithm>
int n,m,INF=1000;
int abs_m1_0(int a){
    if(a<0){//거리를 조정하는 함수이다.
        a=-a;
    }
    a--;
    if(a<0){
        a=0;
    }
    return a;
}
std::vector<std::vector<int>> committees_organize(std::vector<std::vector<bool>>& know_each_other){
    std::vector<bool> used(n,false);//알고 있는 지 여부를 가지고 위원회를 짠다.
    std::vector<std::vector<int>> committees;
    std::vector<int> c;
    for(int i=0;i<n;i++){
        if(!used[i]){
            c.clear();
            std::stack<int> s;
            s.push(i+1);
            used[i]=true;
            while (!s.empty()){
                int k=s.top();
                s.pop();
                c.push_back(k);
                for(int j=0;j<n;j++){
                    if(know_each_other[j][k-1]&&!used[j]){
                        s.push(j+1);
                        used[j]=true;
                    }
                }
            }   
            committees.push_back(c);
        }
    }
    return committees;
}
int dijkstra(std::vector<int>& cmt,std::vector<std::vector<bool>>& keo){//모든 사람을 기준으로 모든 사람의 거리를 도출,
    int ans_idx=-1,ans_cnt=INF;//그 중 최장거리의 최솟값인 인덱스를 반환한다.
    for(int start:cmt){//이 함수가 가장 중요하다.
        std::vector<int> dist(n,INF);
        dist[start-1]=0;
        std::priority_queue<std::pair<int,int>> pq;
        pq.push({0,start});//-1*거리, 인덱스
        while (!pq.empty()){
            int d=-1*pq.top().first,idx=pq.top().second;
            pq.pop();
            if(dist[idx-1]<d){
                continue;
            }
            for(int i:cmt){
                if(keo[i-1][idx-1]){
                    if(dist[i-1]>d+1){
                        dist[i-1]=d+1;
                        pq.push({-d-1,i});
                    }
                }
            }
        }
        std::vector<int> nd;
        for(int i:cmt){
            nd.push_back(dist[i-1]);
        }
        int mx=abs_m1_0(*max_element(nd.begin(),nd.end()));
        if(mx<ans_cnt){
            ans_cnt=mx;
            ans_idx=start;
        }
    }
    return ans_idx;
}
int main() {// 메인 함수로, 알고 있는지 여부를 저장하고, 함수를 써가면서 결론을 도출한다.
    std::cin>>n>>m;
    std::vector<std::vector<bool>> know_each_other (n,std::vector<bool>(n,false));
    int a,b;
    for(int i=0;i<m;i++){
        std::cin>>a>>b;
        know_each_other[a-1][b-1]=true;
        know_each_other[b-1][a-1]=true;
    }
    std::vector<std::vector<int>> committees;
    committees=committees_organize(know_each_other);
    std::cout<<committees.size()<<std::endl;
    std::vector<int> rps;
    for(std::vector<int> cmt:committees){
        int ans=dijkstra(cmt,know_each_other);
        rps.push_back(ans);
    }
    std::sort(rps.begin(),rps.end());
    for(int ans:rps){
        std::cout<<ans<<std::endl;
    }
}
//푸는데 생각보다 오래 걸리기는 했지만 문제만 정확히 읽었으면 좀 더 빨리 풀 수 있었을 것 같다.
//다음에는 좀 더 문제를 자세히 읽어봐야겠다.
//회의 준비
