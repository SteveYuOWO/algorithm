#include <iostream>
using namespace std;
#define N 20
int n;
bool col[N], dg[N], udg[N];
char g[N][N];
void dfs(int u) {
    if(u == n) {
        for(int i = 0; i < n; i++) puts(g[i]);
        putchar('\n');
    }
    for(int i = 0; i < n; i++) {
        if(!col[i] && !dg[u + i] && !udg[u - i + n]) {
            g[u][i] = 'g';
            col[i] = dg[u + i] = udg[u - i + n] = true; 
            dfs(u + 1);
            col[i] = dg[u + i] = udg[u - i + n] = false; 
            g[u][i] = '.';
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}