#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    set<int> div;
    for(int i=1;i<static_cast<int>(floor(sqrt(a)))+1;i++){
        if(a%i==0){
            div.insert(i);
            if(i*i!=a){
                div.insert(static_cast<int>(a/i));
            }
        }
    }
    for(int i=1;i<static_cast<int>(floor(sqrt(b)))+1;i++){
        if(b%i==0){
            div.insert(i);
            if(i*i!=b){
                div.insert(static_cast<int>(b/i));
            }
        }
    }
    for(int i:div){
        cout<<i<<" ";
    }
    return 0;
}
//두 수의 약수 구하기
