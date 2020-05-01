#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N, M, K;
int main() {
    scanf("%d%d", &N, &M);
    vector<pair<int, int>> v(M);
    for(int i = 0; i < M; i++) 
        scanf("%d%d", &v[i].first, &v[i].second);
    scanf("%d", &K);
    vector<int> color(N);
    while(K--) {
        map<int, bool> m;
        for(int i = 0; i < N; i++) {
            scanf("%d", &color[i]);
            m[color[i]] = true;
        }
        bool isRight = true;
        for(int i = 0; i < M; i++) {
            if(color[v[i].first] == color[v[i].second]) {
                isRight = false;
                break;
            }
        }
        if(isRight) printf("%lu-coloring\n", m.size());
        else printf("No\n");
    }
    return 0;
}