#include <iostream>

using namespace std;
int main() {
    int a,b;
    long long c=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        for(int j=i;j>0;j/=10){
            int num=j%10;
            if(num%3==0&&num!=0){
                c++;
            }
        }
    }
    cout<<c;
    return 0;
}
//369 게임 3(Large Test Case)
