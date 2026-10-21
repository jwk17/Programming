#include <iostream>
#include <vector>

using namespace std;
int arr[100050];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k,n,temp;
    cin>>k>>n;
    for(int i=0;i<k;i++){
        cin>>temp;
        arr[i]=temp;
        arr[k]=(arr[k]+temp)%100007;
    }
    for(int i=k+1;i<n;i++){
        arr[i]=(arr[i-1]*2-arr[i-k-1]+200014)%100007;
    }
    cout<<arr[n-1];
    return 0;
}
//K-피보나치 수열 (Large)
