#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
int N, M, K, a, b, n;
set<int> G[99999];
int main() {
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d", &a, &b);
        G[a].insert(b);
        G[b].insert(a);
    }
    scanf("%d", &K);
    while(K--) {
        scanf("%d", &n);
        vector<int> data(n);
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            scanf("%d", &data[i]);
            if(i != 0) m[data[i]]++;
        }
        bool no = false;
        if(data[0] != data[n - 1]) no = true;
        for(int i = 0; i < n - 1; i++) 
            if(G[data[i]].count(data[i + 1]) == 0) no = true;
        if(m.size() != N) no = true;
        for(auto& x: m) if(x.second != 1) no = true;
        printf("%s\n", no ? "NO": "YES");
    }
    return 0;
}