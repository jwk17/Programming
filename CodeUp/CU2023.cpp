#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

int main(){
    long long int n;
    std::cin>>n;
    std::string ans;
    while(n>0){
        n--;
        ans+='A'+n%26;
        n/=26;
    }
    std::reverse(ans.begin(),ans.end());
    std::cout<<ans;
	return 0;
}
//그냥 방법만 찾으면 쉽게 풀 수 있는 문제
//엑셀의 열 순서
