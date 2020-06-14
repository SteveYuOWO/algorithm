#include <iostream>
using namespace std;
int main() {
    int N, cnt, a, b, mon, build, vis[200] = {0}, G[200][200] = {};
    scanf("%d", &N);
    cnt = N * (N - 1) / 2;
    // 读数
    while(cnt--) {
        scanf("%d%d%d%d", &a, &b, &mon, &build);
        if(build) vis[a] = vis[b] = 1; // 如果已经建好
        G[a][b] = G[b][a] = mon;
    }
    int sum = 0;
    // Prim
    for(int i = 1; i <= N; i++) { // 枚举未建好的
        if(vis[i]) continue;
        else {
            int road, money = 9999999;
            for(int j = 1; j <= N; j++) {  // 找到最小金钱数目
                if(G[i][j] != 0 && G[i][j] < money) {
                    money = G[i][j];
                    road = j;
                }
            }
            sum += money;
            vis[road] = vis[i] = 1;
        }
    }
    printf("%d", sum);
    return 0;
}
