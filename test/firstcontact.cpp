#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;
int N, M, a, b, K;
unordered_map<int, unordered_set<int>> m;
unordered_map<int, unordered_set<int>> homo;
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d", &a, &b);
        m[a].insert(b); m[b].insert(a);
        if(a * b >= 0) homo[a].insert(b), homo[b].insert(a);
    }
    scanf("%d", &K);
    while(K--) {
        scanf("%d%d", &a, &b);
        set<pair<int, int>> ans;
        for(auto& x: homo[a]) 
            for(auto& y: homo[b]) 
                if(x != b && y != a && m[x].find(y) != m[x].end()) 
                    ans.insert({abs(x), abs(y)});
        printf("%lu\n", ans.size());
        for(auto& x: ans) 
            printf("%04d %04d\n", x.first, x.second);
    }
    return 0;
}