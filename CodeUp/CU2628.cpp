#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int a1,a2,b1,b2,tmp1,tmp2;
    cin>>a1>>a2>>b1>>b2;
    tmp1=a1,tmp2=a2;
    a1=min(tmp1,tmp2);
    a2=max(tmp1,tmp2);
    if(a1<b1&&b1<a2&&(a2<b2||a1>b2)){
        cout<<"cross";
    }
    else if(a1<b2&&b2<a2&&(a2<b1||a1>b1)){
        cout<<"cross";
    }
    else{
        cout<<"not cross";
    }
    return 0;
}
//케익 자르기
