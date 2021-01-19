#include <iostream>
using namespace std;
const int N = 100010;
string op;
int stk[N], tt, M, x;
int main() {
    cin >> M;
    while(M--) {
        cin >> op;
        if(op == "push") cin >> x, stk[++tt] = x;
        else if(op == "query") cout << stk[tt] << endl;
        else if(op == "pop") tt--;
        else if(op == "empty") cout << (tt > 0 ? "NO": "YES") << endl;
    }
    return 0;
}