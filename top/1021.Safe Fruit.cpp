#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;
struct fruit {
    int id, price;
    bool operator< (const fruit& f) const {
        return id < f.id;
    }
}f;
int main() {
    int N, M, a, b;
    scanf("%d%d", &N, &M);
    unordered_map<int, unordered_set<int>> m;
    while(N--) {
        scanf("%d%d", &a, &b);
        m[a].insert(b);
        m[b].insert(a);
    }
    unordered_set<int> s;
    unordered_map<int, fruit> fruits;
    while(M--) {
        scanf("%d%d", &f.id, &f.price);
        s.insert(f.id);
        fruits[f.id] = f;
    }
    set<fruit> ans;
    for(auto& x: s) {
        bool flag = 1;
        for(auto& y: m[x]) 
            if(s.find(y) != s.end()) flag = 0;
        if(flag) ans.insert(fruits[x]);
    }
    cout << ans.size();
    return 0;
}
