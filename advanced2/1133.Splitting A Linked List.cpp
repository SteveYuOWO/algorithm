#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
using namespace std;
struct node {
    int addr, val, next;
}tmp;
unordered_map<int, node> m;
vector<node> v, bef, aft;
deque<node> deq;
int main() {
    int start, N, K;
    cin >> start >> N >> K;
    while(N--) {
        cin >> tmp.addr >> tmp.val >> tmp.next;
        m[tmp.addr] = tmp;
    }
    while(start != -1) {
        v.push_back(m[start]);
        start = m[start].next;
    }
    for(auto& x: v) {
        if(x.val > K) aft.push_back(x);
        else if(x.val < 0) bef.push_back(x);
        else deq.push_back(x);
    }
    for(auto& x: aft) deq.push_back(x);
    for(auto& x: deq) bef.push_back(x);
    printf("%05d %d", bef[0].addr, bef[0].val);
    for(int i = 1; i < bef.size(); i++)
        printf(" %05d\n%05d %d", bef[i].addr, bef[i].addr, bef[i].val);
    printf(" -1\n");
    return 0;
}