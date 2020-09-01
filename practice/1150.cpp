#include <iostream>
#include <vector>
#include <set>
using namespace std;
int N, M, K, G[300][300], a, b, c;
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        G[a][b] = G[b][a] = c;
    }
    scanf("%d", &K);
    int p, min = 9999999;
    for(int k = 1; k <= K; k++) {
        int n, sum = 0;
        scanf("%d", &n);
        vector<int> v(n); set<int> s;
        for(int i = 0; i < n; i++)
            scanf("%d", &v[i]), s.insert(v[i]);
        bool flag = 1, na = 0;
        if(v[0] != v[n - 1]) flag = 0;
        for(int i = 1; i < n; i++) {
            if(G[v[i]][v[i - 1]] == 0) flag = 0, na = 1;
            sum += G[v[i]][v[i - 1]];
        }
        if(flag == 0 || s.size() != N) {
            if(na != 1) printf("Path %d: %d (Not a TS cycle)\n", k, sum);
            else printf("Path %d: NA (Not a TS cycle)\n", k);
        }else {
            if(sum < min) min = sum, p = k;
            if(v.size() == N + 1) printf("Path %d: %d (TS simple cycle)\n", k, sum);
            else printf("Path %d: %d (TS cycle)\n", k, sum);
        }
    }
    printf("Shortest Dist(%d) = %d\n", p, min);
    return 0;
}