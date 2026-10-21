#include <iostream>
#include <vector>

using namespace std;
vector<int> cnt(10000001,-1);
int solve(long long n){
    if(n==1){
        return 1;
    }
    if(n<=10000000&&cnt[n]!=-1){
        return cnt[n];
    }
    long long next;
    if(n%2==0){
        next=n/2;
    }
    else{
        next=n*3+1;
    }
    int result=solve(next)+1;
    if(n<=10000000){
        cnt[n]=result;
    }
    return result;
}
int main() {
	int a,b;
	cin>>a>>b;
	cnt[1]=1;
    int max_l=0,max_idx=a-1;
    for(int i=a;i<=b;i++){
        int len=solve(i);
        if(len>max_l){
            max_l=len;
            max_idx=i;
        }
    }
    cout<<max_idx<<" "<<max_l;
	return 0;
}
//우박수 길이 (3n+1) (large)
