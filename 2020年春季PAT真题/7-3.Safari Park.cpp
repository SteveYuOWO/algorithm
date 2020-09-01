#include <iostream>
#include <vector>
#include <set>
using namespace std;
int M, N, R, K, a, b;
vector<pair<int, int>> G;
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &N, &R, &K);
    while(R--) {
        scanf("%d%d", &a, &b);
        G.push_back({a, b});
    }
    scanf("%d", &M);
    while(M--) {
        vector<int> v(N + 1);
        set<int> s;
        for(int i = 1; i <= N; i++) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        if(s.size() < K) printf("Error: Too few species.\n");
        else if(s.size() > K) printf("Error: Too many species.\n");
        else {
            bool flag = false;
            for(auto x: G) if(v[x.first] == v[x.second]) flag = true;
            printf("%s\n", !flag ? "Yes": "No");
        }
    }
    return 0;
}