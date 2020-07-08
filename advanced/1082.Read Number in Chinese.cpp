#include <iostream>
#include <cmath>
using namespace std;
string ans;
bool bef = false;
string ge[] = {" ling", " yi", " er", " san", " si", " wu", " liu", " qi", " ba", " jiu"};
void show(int num) {
    bool flag = false;
    if(num / 1000 != 0) ans = ans + ge[num / 1000] + " Qian";
    else if(bef) {
        ans += ge[0];
        bef = true;
    }
    if(num % 1000 / 100 != 0) ans = ans + ge[num % 1000 / 100] + " Bai";
    if(num / 1000 != 0 && num % 1000 / 100 == 0) flag = true;
    if(num % 100 / 10 != 0) {
        if(flag) ans += ge[0];
        ans = ans + ge[num % 100 / 10] + " Shi";
    }
    if((num / 1000 != 0 || num % 1000 / 100 != 0) && num % 100 / 10 == 0) flag = true;
    if(num % 10 != 0) {
        if(flag) ans += ge[0];
        ans += ge[num % 10];
    }
}
int main() {
    int N;
    scanf("%d", &N);
    if(N < 0) ans = ans + " Fu";
    if(N == 0) ans += ge[0];
    N = abs(N);
    int yi = N / 100000000;
    int wan = N % 100000000 / 10000;
    int rel = N % 10000;
    if(yi != 0) {
        ans = ans + ge[yi] + " Yi";
        bef = true;
    }
    if(wan != 0) {
        show(wan);
        ans += " Wan";
        bef = true;
    }
    if(rel != 0) show(rel);
    cout << ans.substr(1);
    return 0;
}
