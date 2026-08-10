#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


std::vector<std::vector<int>> rvs(std::vector<std::vector<int>> vtr){
    std::vector<std::vector<int>> rvtr;
    for(int i=vtr.size()-1;i>=0;i--){
        std::vector<int> p=vtr[i];
        p={p[0],p[2],p[1]};
        rvtr.push_back(p);
    }
    return rvtr;
}

int main() {
    int n;
    std::cin>>n;
    char abc[3]={'A','B','C'};
    std::vector<std::vector<int>> ansfirst={{{1,1,2},{1,2,3}}};
    std::vector<std::vector<int>> anssecond;
    for(int i=0;i<n-1;i++){
        anssecond.insert(anssecond.end(),ansfirst.begin(),ansfirst.end());
        std::vector<int> p={i+2,1,2};
        anssecond.push_back(p);
        std::vector<std::vector<int>> rvtr=rvs(ansfirst);
        anssecond.insert(anssecond.end(),rvtr.begin(),rvtr.end());
        p={i+2,2,3};
        anssecond.push_back(p);
        anssecond.insert(anssecond.end(),ansfirst.begin(),ansfirst.end());
        ansfirst=anssecond;
        anssecond.clear();
    }
    for(int i=0;i<ansfirst.size();i++){
        std::vector<int> path=ansfirst[i];
        //std::cout<<path[0]<<" : "<<abc[path[1]-1]<<"->"<<abc[path[2]-1]<<std::endl;
        printf("%d : %c->%c\n",path[0],abc[path[1]-1],abc[path[2]-1]);
    }
    printf("%ld",ansfirst.size());
    return 0;
}
//메모리 초과 나온 이후 그냥 저렇게 ansfirst,anssecond를 만드니까 시간초과로 실패했고, printf로 바꾸니까 바로 성공했다.
//아이디어만 있으면 나름대로 구현은 어렵지는 않았다.
//1개는 0->1->2이지만 2개는 1개짜리+크기 2 1칸 이동+1개짜리 거꾸로+크기 2 1칸 이동+1개짜리 이런 식으로 만들면 되니 이걸 계속 반복하면 된다.
//최장 경로 하노이탑
