#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
int N, M, a, b, K, tmp;
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    while(N--) {
        scanf("%d%d", &a, &b);
        v.push_back({a, b});
    }
    while(M--) {
        scanf("%d", &K);
        unordered_map<int, int> m; bool no = false;
        while(K--) scanf("%d", &tmp), m[tmp] = 1;
        for(auto& x: v) if(m[x.first] && m[x.second]) no = true;
        printf("%s", no ? "No\n": "Yes\n");
    }
    return 0;
}