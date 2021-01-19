#include <iostream>
using namespace std;
int head, e[100010], ne[100010], idx;
void init() {
    head = -1; idx = 0;
}
void add_to_head(int x) {
    e[idx] = x, ne[idx] = head, head = idx++;
}
void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}
void remove(int k) {
    if(k == -1) head = ne[head];
    else ne[k] = ne[ne[k]];
}
int main() {
    int m, k, x; char op;
    init();
    cin >> m;
    while(m--) {
        cin >> op;
        if(op == 'H') cin >> x, add_to_head(x);
        else if(op == 'D') {
            cin >> k;
            remove(k - 1);
        }
        else cin >> k >> x, add(k - 1, x);
    }
    for(int i = head; i != -1; i = ne[i]) cout << e[i] << " ";
    return 0;
}