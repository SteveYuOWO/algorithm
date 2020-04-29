#include <iostream>
#include <vector>
#include <queue>
#define MAX 9999
using namespace std;
int N, E, a, b;
bool path[MAX][MAX] = {0}, vis[MAX] = {0};
void dfs(int v) {
    vis[v] = 1;
    printf(" %d", v);
    for(int i = 0; i < N; i++)
        if(path[v][i] && !vis[i]) dfs(i);
}
void bfs(int v) {
    queue<int> que;
    que.push(v);
    vis[v] = 1;
    while(!que.empty()) {
        int ele = que.front();
        que.pop();
        printf(" %d", ele);
        for(int i = 0; i < N; i++) 
            if(path[ele][i] && !vis[i]) {
                que.push(i);
                vis[i] = 1;
            }
    }
}
int main() {
    scanf("%d%d", &N, &E);
    while(E--) {
        scanf("%d%d", &a, &b);
        path[a][b] = path[b][a] = 1;
    }
    // dfs
    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            printf("{");
            dfs(i);
            printf(" }\n");
        }
    }
    fill(vis, vis+MAX, 0);
    // bfs
    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            printf("{");
            bfs(i);
            printf(" }\n");
        }
    }
    return 0;
}
