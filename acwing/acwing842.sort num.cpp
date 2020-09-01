#include <iostream>
using namespace std;
const int N = 10;
int n, path[N]; bool vis[N];
void dfs(int u) {
    if(u == n) {
        for(int i = 0; i < n; i++) printf("%d ", path[i]);
        putchar('\n');
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            path[u] = i;
            vis[i] = true;
            dfs(u + 1);
            vis[i] = false;
        }
    }
}
int main() {
    scanf("%d", &n);
    dfs(1);
}