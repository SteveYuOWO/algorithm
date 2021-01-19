#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int N, M, K, a, b, start, end1, minCnt, minTransfer, vis[99999] = {0};
vector<int> G[10000], path, minPath;
unordered_map<int, unordered_map<int, int>> m;
int transfer(vector<int> path) {
    int cnt = -1, preLine = 0;
    for(int i = 1; i < path.size(); i++) {
        if(m[path[i]][path[i - 1]] != preLine) {
            cnt++;
            preLine = m[path[i]][path[i - 1]];
        }
    }
    return cnt;
}
void dfs(int v, int cnt) {
    if(v == end1) {
        if(cnt < minCnt || (cnt == minCnt && transfer(path) < minTransfer)) {
            minCnt = cnt;
            minTransfer = transfer(path);
            minPath = path;
        }
        return;
    }
    for(int i = 0; i < G[v].size(); i++) {
        if(!vis[G[v][i]]) {
            vis[G[v][i]] = 1;
            path.push_back(G[v][i]);
            dfs(G[v][i], cnt + 1);
            path.pop_back();
            vis[G[v][i]] = 0;
        }
    }
}
int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d%d", &M, &a);
        for(int j = 1; j < M; j++) {
            scanf("%d", &b);
            G[a].push_back(b);
            G[b].push_back(a);
            m[a][b] = m[b][a] = i;
            a = b;
        }
    }
    scanf("%d", &K);
    while(K--) {
        scanf("%d%d", &start, &end1);
        minCnt = 99999; minTransfer = 99999;
        path.clear();
        path.push_back(start);
        dfs(start, 0);
        printf("%lu\n", minPath.size() - 1);
        int preTransfer = start, preLine = 0;
        for(int i = 1; i < minPath.size(); i++) {
            if(m[minPath[i]][minPath[i - 1]] != preLine) {
                if(preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, minPath[i-1]);
                preLine = m[minPath[i]][minPath[i - 1]];
                preTransfer = minPath[i - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
    }
    return 0;
}