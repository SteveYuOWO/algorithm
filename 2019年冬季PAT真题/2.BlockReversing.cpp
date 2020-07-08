#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node {
    int addr, data, next;
}n[100100];
int start, N, K, a;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d%d", &start, &N, &K);
    unordered_map<int, int> m;
    while(N--) {
        scanf("%d", &a);
        n[a].addr = a;
        scanf("%d%d", &n[a].data, &n[a].next);
    }
    vector<vector<node>> v;
    while(start != -1) {
        int cnt = K;
        vector<node> v_tmp;
        while(cnt-- && start != -1) {
            v_tmp.push_back(n[start]);
            start = n[start].next;
        }
        v.push_back(v_tmp);
    }
    reverse(v.begin(), v.end());
    vector<node> ans;
    for(auto& x: v) for(auto& y: x) ans.push_back(y);
    printf("%05d %d", ans[0].addr, ans[0].data);
    for(int i = 1; i < ans.size(); i++) 
        printf(" %05d\n%05d %d", ans[i].addr, ans[i].addr, ans[i].data);
    printf(" -1\n");
    return 0;
}
