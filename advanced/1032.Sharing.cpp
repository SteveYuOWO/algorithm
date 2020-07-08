#include <iostream>
#include <unordered_map>
using namespace std;
struct node{
    string addr, ch, next;
};
/**
最后一个case错是因为，没有理解，同一个字母可以有多个地址
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    string addr, addr2;
    node tmp;
    unordered_map<string, node> m;
    unordered_map<string, bool> m2;
    cin >> addr >> addr2 >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp.addr >> tmp.ch >> tmp.next;
        m[tmp.addr] = tmp;
    }
    while(addr != "-1") {
        m2[addr] = true;
        addr = m[addr].next;
    }
    while(addr2 != "-1") {
        if(m2[addr2]) {
            cout << m[addr2].addr << endl;
            system("pause");
            return 0;
        }
        addr2 = m[addr2].next;
    }
    cout << -1 << endl;
    system("pause");
    return 0;
}
