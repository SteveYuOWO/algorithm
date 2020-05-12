#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
int N, M, a, b;
unordered_map<int, set<int>> s;
set<int> query;
int main() {
    scanf("%d", &N);
    while(N--) {
        scanf("%d%d", &a, &b);
        s[a].insert(b);
        s[b].insert(a);
    }
    scanf("%d", &M);
    while(M--) {
        scanf("%d", &a);
        query.insert(a);
    }
    for(auto& x: s) {
        auto it = query.find(x.first);
        if(it == query.end()) continue;
        for(auto& y: s[x.first]) {
            auto it2 = query.find(y);
            if(it2 != query.end()) {
                query.erase(it);
                query.erase(it2);
                break;
            }
        }
    }
    printf("%lu\n", query.size());
    bool start = true;
    for(auto& x: query) {
        if(start == true) {
            printf("%05d", x);
            start = false;
        } else printf(" %05d", x);
    }
    return 0;
}