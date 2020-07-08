#include "iostream"
#include "vector"
#include "algorithm"
#define NUM 99999
using namespace std;
vector<int> path[NUM];
int current_vetex;
bool vis[NUM];
void dfs(int v) {
    if(v == current_vetex) return;
    vis[v] = true;
    for(int i = 0; i < path[v].size(); i++) 
        if(vis[path[v][i]] == false) dfs(path[v][i]);
}
int main() {
    int N, M, K;
    int tmp1, tmp2;
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &tmp1, &tmp2);
        path[tmp1].push_back(tmp2);
        path[tmp2].push_back(tmp1);
    }
    for(int i = 0; i < K; i++) {
        scanf("%d", &current_vetex);
        fill(vis, vis + NUM, false);
        int cnt = 0;
        for(int j = 1; j <= N; j++) {
            if(j != current_vetex && vis[j] == false) {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}
