#include <iostream>
#include <vector>
using namespace std;
int N, M, K, a, b, in[1010];
vector<int> v[1010];
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d", &a, &b);
        v[a].push_back(b); in[b]++;
    }
    scanf("%d", &K);
    vector<int> ans;
    for(int k = 0; k < K; k++) {
        vector<int> v2(N), cp(in, in + N + 1);
        bool flag = 1;
        for(int i = 0; i < N; i++) {
            scanf("%d", &v2[i]);
            if(cp[v2[i]] != 0) flag = 0;
            for(auto& x: v[v2[i]]) cp[x]--;
        }
        if(!flag) ans.push_back(k);
    }
    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);
    return 0;
}