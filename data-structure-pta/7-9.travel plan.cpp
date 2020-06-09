#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 999999
using namespace std;
int N, M, S, D, c1, c2, len, mon, dis[510], money[510], vis[510] = {0};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
struct edge {
    int len, mon;
}e[510][510];
int main() {
    scanf("%d%d%d%d", &N, &M, &S, &D);
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d%d", &c1, &c2, &len, &mon);
        e[c1][c2].len = e[c2][c1].len = len;
        e[c1][c2].mon = e[c2][c1].mon = mon;
    }
    fill(dis, dis + 510, INF);
    fill(money, money + 510, INF);
    dis[S] = 0;
    money[S] = 0;
    q.push({0, S});
    while(q.size()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int v = 0; v < N; v++) {
            if(!vis[v] && e[u][v].len) {
                if(dis[v] > dis[u] + e[u][v].len) {
                    dis[v] = dis[u] + e[u][v].len;
                    money[v] = money[u] + e[u][v].mon;
                } else if(dis[v] == dis[u] + e[u][v].len && money[v] > money[u] + e[u][v].mon) {
                    money[v] = money[u] + e[u][v].mon;
                }
                q.push({dis[v], v});
            }
        }
    }
    printf("%d %d", dis[D], money[D]);
    return 0;
}
