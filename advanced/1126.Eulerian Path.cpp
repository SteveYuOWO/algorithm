#include <iostream>
#include <vector>
using namespace std;
int degree[99999] = {0}, vis[99999] = {0}, N, M, a, b, odd = 0, conn = true, part = 0;
vector<int> G[99999];
void dfs(int n) {
    if(vis[n]) return;
    vis[n] = 1;
    for(int i = 0; i < G[n].size(); i++)
        dfs(G[n][i]);
}
int main() {
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d", &a, &b);
        degree[a]++; degree[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 判断连通分量
    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {
            dfs(i);
            part++;
        }
    }
    if(part > 1) conn = false; // 如果连通分量大于1，则设置false
    for(int i = 1; i <= N; i++) 
        if(degree[i] % 2 != 0) odd++;
    printf("%d", degree[1]);
    for(int i = 2; i <= N; i++) 
        printf(" %d", degree[i]);
    if(odd == 0 && conn) printf("\nEulerian\n");
    else if(odd == 2 && conn) printf("\nSemi-Eulerian\n");
    else printf("\nNon-Eulerian\n");
    return 0;
}