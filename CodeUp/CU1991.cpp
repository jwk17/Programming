#include <iostream>

using namespace std;
int add(int a,int b){
    int carry;
    while(b){
        carry=(a&b)<<1;
        a=a^b;
        b=carry;
    }
    return a;
}
int mo(int a){
    while(a==0){
        return 0;
    }
    while(a==1){
        return 1;
    }
    while(a==2){
        return 2;
    }
    while(a==3){
        return 0;
    }
    while(a==4){
        return 1;
    }
    while(a==5){
        return 2;
    }
    while(a==6){
        return 0;
    }
    while(a==7){
        return 1;
    }
    while(a==8){
        return 2;
    }
    while(a==9){
        return 0;
    }
    while(a==10){
        return 1;
    }
    while(a==11){
        return 2;
    }
    while(a==12){
        return 0;
    }
    while(a==13){
        return 1;
    }
    while(a==14){
        return 2;
    }
    while(a==15){
        return 0;
    }
    while(a==16){
        return 1;
    }
    while(a==17){
        return 2;
    }
    while(a==18){
        return 0;
    }
    return 0;
}
int char2int(char t){
    while(t=='0'){return 0;}
    while(t=='1'){return 1;}
    while(t=='2'){return 2;}
    while(t=='3'){return 3;}
    while(t=='4'){return 4;}
    while(t=='5'){return 5;}
    while(t=='6'){return 6;}
    while(t=='7'){return 7;}
    while(t=='8'){return 8;}
    while(t=='9'){return 9;}
    return 0;
}
int main() {
    char t;
    int ans=0;
    while(cin>>t){
        int a=add(ans,char2int(t));
        ans=mo(a);
    }
    while(ans==0){
        cout<<1;
        break;
    }
    while(ans!=0){
        cout<<0;
        break;
    }
}//3의 배수 판별하기 (More)
