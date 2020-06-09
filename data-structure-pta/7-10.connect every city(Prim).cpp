#include <iostream>
#include <queue>
#include <vector>
#define INF 999999
using namespace std;
int N, M, a, b, c;
int e[1010][1010] = {0}, dist[1010], vis[1010] = {0};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int main() {
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    fill(dist, dist + 1010, INF);
    dist[1] = 0;
    q.push({0, 1});
    while(q.size()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int v = 1; v <= N; v++) {
            if(!vis[v] && e[u][v] && dist[v] > e[u][v])  {
                dist[v] = e[u][v]; 
                q.push({dist[v], v});
            }
        }
    }
    int sum = 0, conn = 1;
    for(int i = 1; i <= N; i++) {
        sum += dist[i];
        if(!vis[i]) conn = 0;
    }
    if(!conn) printf("-1\n");
    else printf("%d\n", sum);
    
    return 0;
}
