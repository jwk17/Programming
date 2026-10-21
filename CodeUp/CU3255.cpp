#include <iostream>
#include <vector>

using namespace std;
int sum_tree(int (&tree)[300000],int l,int r){
    int ans=0;
    l+=131071;
    r+=131071;
    while(l<=r){
        if(l%2==1){
            ans+=tree[l];
            l+=1;
        }
        if(r%2==0){
            ans+=tree[r];
            r-=1;
        }
        l=l/2;
        r=r/2;
    }
    return ans;
}
void mod_tree(int (&tree)[300000],int l,int r,bool plus,int k){
    l+=131071;
    r+=131071;
    for(int i=l;i<=r;i++){
        if(plus){
            tree[i]+=k;
        }
        else{
            tree[i]-=k;
        }
    }
    for(int i=131071;i>0;i--){
        tree[i]=tree[i*2]+tree[i*2+1];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,op,x,y,k;
    cin>>n;
    int tree[300000]={0,};
    for(int i=0;i<n;i++){
        cin>>tree[i+131072];
    }
    for(int i=131071;i>0;i--){
        tree[i]=tree[i*2]+tree[i*2+1];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>op;
        if(op==0){
            cin>>x>>y;
            cout<<sum_tree(tree,x,y)<<'\n';
        }
        else{
            cin>>x>>y>>k;
            mod_tree(tree,x,y,op==1,k);
        }
    }
    return 0;
}
//기억력 테스트 11
