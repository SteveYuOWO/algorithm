#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int M, N, a, b;
bool G[10100][10100] = {0};
int bfs(int v) {
    bool vis[10010] = {0};
    int depth = 0, tail, last = v, cnt = 0;
    queue<int> que;
    que.push(v);
    while(!que.empty()) {
        int tmp = que.front();
        que.pop();
        vis[tmp] = 1;
        cnt++;
        for(int i = 0; i < N; i++)
            if(G[i][tmp] && !vis[i]) {
                que.push(i);
                tail = i;
                vis[i] = 1; // 这句没有会超时
            }
        if(tmp == last) {
            depth++;
            last = tail;
        }
        if(depth > 6) break;
    }
    return cnt;
}
int main() {
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d", &a, &b);
        G[a-1][b-1] = G[b-1][a-1] = 1;
    }
    for(int i = 0; i < N; i++) {
        printf("%d: %.2f%%\n", i + 1, (bfs(i) * 100.0) / N);
    }
    return 0;
}