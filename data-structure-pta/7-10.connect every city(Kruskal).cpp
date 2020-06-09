#include <iostream>
#include <queue>
#include <vector>
#define INF 999999
using namespace std;
int N, M, a, b, c;
int vis[1010] = {0};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int main() {
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d%d", &a, &b, &c);
        q.push({c, a * 10000 + b});
    }
    int sum = 0, conn = 1;
    while(q.size()) {
        int m = q.top().second / 10000;
        int n = q.top().second % 10000;
        if(!vis[m] || !vis[n]) {
            sum += q.top().first;
            vis[m] = vis[n] = 1;
        }
        q.pop();
    }
    printf("%d\n", sum);
    return 0;
}
