#include <iostream>
using namespace std;
const int n = 100010;
int N, stk[n], tt, x;
int main() {
    cin >> N;
    while(N--) {
        cin >> x;
        while(tt && stk[tt] >= x) tt--;
        if(tt) cout << stk[tt] << " ";
        else cout << "-1 ";
        stk[++tt] = x;
    }
    return 0;
}