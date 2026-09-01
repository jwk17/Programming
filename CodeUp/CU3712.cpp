#include <iostream>
using namespace std;
int power(int b,int i){
    if(i==1) return b;
    return (power(b,i-1)*b)%100000007;
}
int main() {
    int n;
    cin>>n;
    if(n%3!=0){
        cout<<0;
    }
    else{
        cout<<power(2,(int) n/3);
    }
    return 0;
}
//거듭 제곱을 구현하면 되는데, 오버플로우를 방지하기 위해 직접 재귀로 구현했다
//블럭 채우기 2
