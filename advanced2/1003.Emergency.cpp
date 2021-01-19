#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c1, c2;
int edge[510][510], weight[510], dis[510], num[510], w[510];
bool vis[510];
const int inf = 99999999;
int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    fill(edge[0], edge[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    int a, b, c;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &c);
        edge[a][b] = edge[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for(int i = 0;i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        vis[u] = true;
        for(int  v = 0; v < n; v++) {
            if(vis[v] == false && edge[u][v] != inf) {
                if(dis[u] + edge[u][v] < dis[v]) {
                    dis[v] = dis[u] + edge[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                }else if(dis[u] + edge[u][v] == dis[v]) {
                    num[v] = num[v] + num[u];
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}
