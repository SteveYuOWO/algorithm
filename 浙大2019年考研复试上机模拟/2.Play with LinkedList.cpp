#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct node {
    int addr, data, next;
}n;
int start, N, K;
unordered_map<int, node> m;
vector<node> L1, L2, ans;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d%d", &start, &N, &K);
    while(N--) {
        scanf("%d%d%d", &n.addr, &n.data, &n.next);
        m[n.addr] = n;
    }
    while(start != -1) {
        if(K-- > 0) L1.push_back(m[start]);
        else L2.push_back(m[start]);
        start = m[start].next;
    }
    while(!L1.empty() || !L2.empty()) {
        if(L1.size()) {
            ans.push_back(L1[L1.size() - 1]);
            L1.pop_back();
        }
        if(L2.size()) {
            ans.push_back(L2[L2.size() - 1]);
            L2.pop_back();
        }
    }
    printf("%05d %d", ans[0].addr, ans[0].data);
    for(int i = 1; i < ans.size(); i++) 
        printf(" %05d\n%05d %d", ans[i].addr, ans[i].addr, ans[i].data);
    printf(" -1\n");
    return 0;
}
