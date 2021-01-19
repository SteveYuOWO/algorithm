#include <iostream>
using namespace std;
const int INF = 99999999, n = 510;
int N, M, C1, C2;
int w[n], e[n][n], vis[n], dis[n], num[n], weight[n];
int main() {
    // freopen("in.txt", "r", stdin);
    fill(e[0], e[0] + n * n, INF);
    fill(dis, dis + n, INF);
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    for(int i = 0; i < N; i++)
        scanf("%d", &w[i]);
    int a, b, d;
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &d);
        e[a][b] = e[b][a] = d;
    }
    dis[C1] = 0; num[C1] = 1; weight[C1] = w[C1];
    
    while(true) {
        int u = -1, minn = INF;
        for(int i = 0; i < N; i++) 
            if(!vis[i] && dis[i] < minn) 
                u = i, minn = dis[i];
        if(u == -1) break;
        vis[u] = true;
        for(int v = 0; v < N; v++) {
            if(!vis[v] && e[u][v] != INF) {
                if(e[u][v] + dis[u] < dis[v]) {
                    dis[v] = e[u][v] + dis[u];
                    num[v] = num[u];
                    weight[v] = weight[u] + w[v];
                } else if(e[u][v] + dis[u] == dis[v]) {
                    num[v] = num[v] + num[u];
                    if(w[v] + weight[u] > weight[v]) 
                        weight[v] = weight[u] + w[v];
                }
            }
        }
    }
    printf("%d %d\n", num[C2], weight[C2]);
    return 0;
}