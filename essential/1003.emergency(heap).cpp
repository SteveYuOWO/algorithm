#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int n = 510, INF = 99999999;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int N, M, C1, C2;
int dis[n], num[n], weight[n], w[n], e[n][n], vis[n];
int main() {
    // freopen("in.txt", "r", stdin);
    fill(dis, dis + n, INF);
    fill(e[0], e[0] + n * n, INF);
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    for(int i = 0; i < N; i++) 
        scanf("%d", &w[i]);
    int a, b, c;
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    num[C1] = 1; weight[C1] = w[C1]; dis[C1] = 0;
    q.push({0, C1});
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int v = 0; v < N; v++) {
            if(e[u][v] != INF && !vis[v]) {
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    weight[v] = weight[u] + w[v];
                } else if(dis[u] + e[u][v] == dis[v]) {
                    num[v] = num[u] + num[v];
                    if(weight[u] + w[v] > weight[v]) 
                        weight[v] = weight[u] + w[v];
                }
                q.push({dis[v], v});
            }
        }
    }
    printf("%d %d\n", num[C2], weight[C2]);
    return 0;
}