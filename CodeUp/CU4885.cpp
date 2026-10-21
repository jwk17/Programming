#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ANS=100;
void move(int &a,int ac,int &b,int bc){
    if(b+a<=bc){
        b=b+a;
        a=0;
    }
    else{
        a-=(bc-b);
        b=bc;
    }
}
void recur(int a,int b,int ac,int bc,int moves,int atar,int btar){
    if(a==atar&&b==btar){
        ANS=min(ANS,moves);
        return;
    }
    if(moves>10) return;
    recur(ac,b,ac,bc,moves+1,atar,btar);
    recur(a,bc,ac,bc,moves+1,atar,btar);
    recur(0,b,ac,bc,moves+1,atar,btar);
    recur(a,0,ac,bc,moves+1,atar,btar);
    int tmp1=a,tmp2=b;
    move(tmp1,ac,tmp2,bc);
    recur(tmp1,tmp2,ac,bc,moves+1,atar,btar);
    tmp1=a,tmp2=b;
    move(tmp2,bc,tmp1,ac);
    recur(tmp1,tmp2,ac,bc,moves+1,atar,btar);
}
int main() {
    int a,b,ac,bc;
    cin>>ac>>bc>>a>>b;
    recur(0,0,ac,bc,0,a,b);
    if(ANS==100){
        cout<<-1;
    }
    else{
        cout<<ANS;
    }
    return 0;
}
//물통 (Tiny)
