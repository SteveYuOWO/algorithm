#include <iostream>
#include <vector>
using namespace std;
int N, M, K, num, a, b, G[220][220] = {0};
bool judgeConnect(vector<int>& v) {
    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v.size(); j++)
            if(v[i] != v[j] && G[v[i]][v[j]] == 0) return false;
    return true;
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d", &a, &b);
        G[a][b] = G[b][a] = 1;
    }
    scanf("%d", &K);
    for(int k = 1; k <= K; k++) {
        int vis[220] = {};
        scanf("%d", &num);
        vector<int> v(num);
        for(int i = 0; i < num; i++) {
            scanf("%d", &v[i]);
            vis[v[i]] = 1;
        }
        bool hasPrint = false;
        for(int i = 1; i <= N; i++) {
            if(vis[i]) continue;
            v.push_back(i);
            if(judgeConnect(v)) {
                printf("Area %d may invite more people, such as %d.\n", k, i);
                hasPrint = true;
                break;
            }
            v.pop_back();
        }
        if(hasPrint) continue;
        bool ans = judgeConnect(v);
        if(ans) printf("Area %d is OK.\n", k);
        else printf("Area %d needs help.\n", k);
    }
    return 0;
}
