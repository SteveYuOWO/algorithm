#include <iostream>
#include <map>
using namespace std;
int N, M, K, color[10100];
pair<int, int> p[10010];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d", &N, &M);
    for(int i = 0; i < M; i++) 
        scanf("%d%d", &p[i].first, &p[i].second);
    scanf("%d", &K);
    while(K--) {
        map<int, bool> m;
        for(int i = 0; i < N; i++) {
            scanf("%d", &color[i]);
            m[color[i]] = 1;
        }
        bool flag = 1;
        for(int i = 0; i < M; i++) {
            if(color[p[i].first] == color[p[i].second]) {
                flag = 0;
                printf("No\n");
                break;
            }
        }
        if(flag) printf("%lu-coloring\n", m.size());
    }
    return 0;
}
