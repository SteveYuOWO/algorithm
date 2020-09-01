#include <iostream>
#include <vector>
#include <set>
using namespace std;
int N, M, a, b, K;
vector<pair<int, int>> e;
int main() {
    // 图染色问题
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d", &a, &b);
        e.push_back({a, b});
    }
    scanf("%d", &K);
    while(K--) {
        vector<int> v(N); set<int> s;
        for(int i = 0; i < N; i++)
            scanf("%d", &v[i]), s.insert(v[i]);
        bool yes = true;
        for(auto& x: e) if(v[x.first] == v[x.second]) yes = false;
        if(yes) printf("%lu-coloring\n", s.size());
        else puts("No");
    }
    return 0;
}