#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int ANS=0;
void recur(string st,int s){
    if(st.size()==0){
        ANS=max(ANS,s);
        return;
    }
    int fst=*st.begin()-'0';
    if(st.size()>=1){
        s+=fst;
        st.erase(st.begin());
    }
    recur(st,s);
    if(st.size()>=1){
        s+=9*fst+(*st.begin()-'0');
        st.erase(st.begin());
    }
    recur(st,s);
}
int main() {
    string str;
    cin>>str;
    recur(str,0);
    cout<<ANS;
    return 0;
}
//숫자 더하기 (Easy)
