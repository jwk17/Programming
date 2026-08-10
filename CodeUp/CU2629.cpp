#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

int main() {
    int n,p;
    std::cin>>n>>p;
    std::vector<std::vector<double>> xyp;
    for(int i=0;i<n;i++){
        double x,y,peo;
        std::cin>>x>>y>>peo;
        std::vector<double> v;
        v.push_back(std::sqrt(std::pow(x,2)+std::pow(y,2)));
        v.push_back(x);
        v.push_back(y);
        v.push_back(peo);
        xyp.push_back(v);
    }
    std::sort(xyp.begin(),xyp.end());
    std::vector<int> exp_p;
    int count=p;
    if(count>=1000000){
        std::cout<<"0.000";
    }
    else{
        for (int i=0;i<n;i++){
            count+=xyp[i][3];
            if(count>=1000000){
                std::cout<<std::fixed<<std::setprecision(3)<<xyp[i][0];
                break;
            }
        }
    }
    if(count<1000000){
        std::cout<<-1;
    }
    return 0;
}
//거리순으로 정렬한다음 하나씩 하나씩 해보면서 딱 100만을 넘긴다면 그 거리를 출력한다.
//광역시
