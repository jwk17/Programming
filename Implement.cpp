#include <iostream>
#include <string>
using namespace std;
int pow2[32] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,-2147483648};
void setBit(int& mask, int idx, bool b) {//실제 2^n 수를 대입해 비트를 설정
    if (b) {
        mask |= idx;
    }
    else {
        mask &= ~idx;
    }
}
void setBitIdx(int& mask, int idx, bool b) {//idx를 대입해 idx 번째 비트를 설정
    if (b) {
        mask |= pow2[idx];
    }
    else {
        mask &= ~pow2[idx];
    }
}
bool getBit(int mask, int idx) {//실제 2^n 수를 대입해 비트를 가져ㅗㅁ
    return (mask & idx) != 0;
}
bool getBitIdx(int mask, int idx) {//idx를 대입해 idx 번째 비트를 가져옴
    return (mask & pow2[idx]) != 0;
}
bool is_negative(int k) {//음/양 체크
    return getBitIdx(k, 31);
}
void leftshift(int& a) {//좀 더러운 <<
    setBitIdx(a, 31, getBitIdx(a, 30));
    setBitIdx(a, 30, getBitIdx(a, 29));
    setBitIdx(a, 29, getBitIdx(a, 28));
    setBitIdx(a, 28, getBitIdx(a, 27));
    setBitIdx(a, 27, getBitIdx(a, 26));
    setBitIdx(a, 26, getBitIdx(a, 25));
    setBitIdx(a, 25, getBitIdx(a, 24));
    setBitIdx(a, 24, getBitIdx(a, 23));
    setBitIdx(a, 23, getBitIdx(a, 22));
    setBitIdx(a, 22, getBitIdx(a, 21));
    setBitIdx(a, 21, getBitIdx(a, 20));
    setBitIdx(a, 20, getBitIdx(a, 19));
    setBitIdx(a, 19, getBitIdx(a, 18));
    setBitIdx(a, 18, getBitIdx(a, 17));
    setBitIdx(a, 17, getBitIdx(a, 16));
    setBitIdx(a, 16, getBitIdx(a, 15));
    setBitIdx(a, 15, getBitIdx(a, 14));
    setBitIdx(a, 14, getBitIdx(a, 13));
    setBitIdx(a, 13, getBitIdx(a, 12));
    setBitIdx(a, 12, getBitIdx(a, 11));
    setBitIdx(a, 11, getBitIdx(a, 10));
    setBitIdx(a, 10, getBitIdx(a, 9));
    setBitIdx(a, 9, getBitIdx(a, 8));
    setBitIdx(a, 8, getBitIdx(a, 7));
    setBitIdx(a, 7, getBitIdx(a, 6));
    setBitIdx(a, 6, getBitIdx(a, 5));
    setBitIdx(a, 5, getBitIdx(a, 4));
    setBitIdx(a, 4, getBitIdx(a, 3));
    setBitIdx(a, 3, getBitIdx(a, 2));
    setBitIdx(a, 2, getBitIdx(a, 1));
    setBitIdx(a, 1, getBitIdx(a, 0));
    setBitIdx(a, 0, false);
}
void rightshift(int& a) {//좀 더러운 >>
    int orig = a;
    setBitIdx(a, 0, getBitIdx(orig, 1));
    setBitIdx(a, 1, getBitIdx(orig, 2));
    setBitIdx(a, 2, getBitIdx(orig, 3));
    setBitIdx(a, 3, getBitIdx(orig, 4));
    setBitIdx(a, 4, getBitIdx(orig, 5));
    setBitIdx(a, 5, getBitIdx(orig, 6));
    setBitIdx(a, 6, getBitIdx(orig, 7));
    setBitIdx(a, 7, getBitIdx(orig, 8));
    setBitIdx(a, 8, getBitIdx(orig, 9));
    setBitIdx(a, 9, getBitIdx(orig, 10));
    setBitIdx(a, 10, getBitIdx(orig, 11));
    setBitIdx(a, 11, getBitIdx(orig, 12));
    setBitIdx(a, 12, getBitIdx(orig, 13));
    setBitIdx(a, 13, getBitIdx(orig, 14));
    setBitIdx(a, 14, getBitIdx(orig, 15));
    setBitIdx(a, 15, getBitIdx(orig, 16));
    setBitIdx(a, 16, getBitIdx(orig, 17));
    setBitIdx(a, 17, getBitIdx(orig, 18));
    setBitIdx(a, 18, getBitIdx(orig, 19));
    setBitIdx(a, 19, getBitIdx(orig, 20));
    setBitIdx(a, 20, getBitIdx(orig, 21));
    setBitIdx(a, 21, getBitIdx(orig, 22));
    setBitIdx(a, 22, getBitIdx(orig, 23));
    setBitIdx(a, 23, getBitIdx(orig, 24));
    setBitIdx(a, 24, getBitIdx(orig, 25));
    setBitIdx(a, 25, getBitIdx(orig, 26));
    setBitIdx(a, 26, getBitIdx(orig, 27));
    setBitIdx(a, 27, getBitIdx(orig, 28));
    setBitIdx(a, 28, getBitIdx(orig, 29));
    setBitIdx(a, 29, getBitIdx(orig, 30));
    setBitIdx(a, 30, getBitIdx(orig, 31));
    setBitIdx(a, 31, false);
}
int add(int a, int b) {//더하기
    while (b) {
        int carry = a & b;
        leftshift(carry);
        a = a ^ b;
        b = carry;
    }
    return a;
}
int inc(int a) {//1 증가
    return add(a, 1);
}
int subt(int a, int b) {//빼기
    b = inc(~b);
    return add(a, b);
}
int sign_reverse(int k) {//음->양 혹은 양->음
    k = inc(~k);
    return k;
}
int mult(int a, int b) {//곱하기
    bool m = false;
    if (is_negative(a)) {
        m = !m;
        a = inc(~a);
    }
    if (is_negative(b)) {
        m = !m;
        b = inc(~b);
    }
    int ans = 0;
    int i = 1;
    int al = a;
    while (i) {
        if (getBit(b, i)) {
            ans = add(ans, al);
        }
        leftshift(i);
        leftshift(al);
    }
    if (m) {
        ans = inc(~ans);
        return ans;
    }
    return ans;
}
int quot(int a, int b) {//몫
    bool m = false;
    if (is_negative(a)) {
        m = !m;
        a = inc(~a);
    }
    if (is_negative(b)) {
        m = !m;
        b = inc(~b);
    }
    int low = 0, high = a;

    while (!is_negative(subt(high, low))) {
        int s = subt(high, low);
        rightshift(s);
        int mid = (add(low, (s)));
        if (!is_negative(subt(a, mult(mid, b))) && is_negative(subt(a, mult(add(mid, 1), b)))) {
            if (m) {
                mid = inc(~mid);
            }
            return mid;
        }
        else if (is_negative(subt(mult(mid, b), a))) {
            low = add(mid, 1);
        }
        else {
            high = subt(mid, 1);
        }
    }
    if (m) {
        low = inc(~low);
    }
    return low;
}
int mod(int a, int b) {//나머지
    return subt(a, (mult(b, quot(a, b))));
}
string divi(int a, int b) {//나누기의 값을 스트링으로 리턴(stof 쓰면 될 것 같긴 하지만 float 전용 덧셈을 어떻게 만드는지를 모름)
    bool m = false;
    if (is_negative(a)) {
        m = !m;
        a = sign_reverse(a);
    }
    if (is_negative(b)) {
        m = !m;
        b = sign_reverse(b);
    }
    string st;
    if (m) {
        st.push_back((char)45);
        st.insert(1, to_string(quot(a, b)));
    }
    else {
        st.insert(0, to_string(quot(a, b)));
    }
    st.push_back('.');
    int i = 0;
    while (is_negative(subt(i, 6))) {
        a = mod(a, b);
        a = mult(a, 10);
        st.push_back((char)add('0', quot(a, b)));
        i = inc(i);
    }
    return st;
}
int main() {//+,-,*,/,<<,>>,!=,==,>,<는 출력에도 하나도 포함되지 않음
    int a, b;
    scanf("%d %d", &a, &b);
    printf("A plus B = %d\n", add(a, b));//원래는 cout랑 cin이였지만 <<,>>이 들어가서 printf,scanf으로 바꿈
    printf("A minus B = %d\n", subt(a, b));
    printf("A × B = %d\n", mult(a, b));
    if (b == 0) {
        printf("No Zero Division!!!\n");
    }
    else {
        printf("A Quotient B = %d\n", quot(a, b));
    }
    if (b == 0) {
        printf("No Zero Division!!!\n");
    }
    else {
        printf("A Mod B = %d\n", mod(a, b));
    }
    if (b == 0) {
        printf("No Zero Division!!!\n");
    }
    else {
        string d = "A ÷ B = ";
        d.append(divi(a, b));
        d.append("\n");
        printf("%s", d.c_str());
    }
    return 0;
}
//+,-,*,/,<<,>>,<,>,==,!=,>=,<= 등 없이 &^~|로만 산술 연산자 구현하기
