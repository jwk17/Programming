#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

int n,open1,open2,l;
int has_to_use[20];
bool is_opened[20];
int ans=1e9;
void recur(int open1,int open2,int idx,int calc){
    if(idx==l){
        ans=std::min(calc,ans);
        return;
    }
    if(calc>=ans){
        return;
    }
    recur(has_to_use[idx],open2,idx+1,calc+std::abs(open1-has_to_use[idx]));
    recur(has_to_use[idx],open1,idx+1,calc+std::abs(open2-has_to_use[idx]));
}

int main(){
    std::cin>>n>>open1>>open2>>l;
    for(int i=0;i<l;i++){
        std::cin>>has_to_use[i];
    }
    is_opened[open1-1]=true;
    is_opened[open2-1]=true;
    recur(open1,open2,0,0);
    std::cout<<ans;
	return 0;
}
//처음으로 C++로 푼 문제는 아니지만, C++로 푼 첫 꽤 어려운? 문제였다.
//확실히 파이썬보다 빠른게 느껴진다.
#벽장문의 이동
