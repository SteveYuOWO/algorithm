#include <iostream>
using namespace std;
const int N = 100010;
int q[N], hh, tt = -1, M, x;
string op;
int main() {
    cin >> M;
    while(M--) {
        cin >> op;
        if(op == "push") cin >> x, q[++tt] = x;
        else if(op == "pop") hh++;
        else if(op == "empty") cout << (hh <= tt ? "NO": "YES") << endl;
        else if(op == "query") cout << q[hh] << endl;
    }
    return 0;
}