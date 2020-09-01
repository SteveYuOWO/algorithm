#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int N, M, K, a, b, m, G[210][210];
bool isClique(vector<int> v) {
    for(int i = 0; i < v.size() - 1; i++)
            for(int j = i + 1; j < v.size(); j++)
                if(!G[v[i]][v[j]]) return false;
    return true;
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    while(M--) scanf("%d%d", &a, &b), G[a][b] = G[b][a] = 1;
    scanf("%d", &K);
    while(K--) {
        unordered_set<int> s;
        scanf("%d", &m);
        vector<int> v(m);
        for(int i = 0; i < m; i++)
            scanf("%d", &v[i]), s.insert(v[i]);
        if(!isClique(v)) printf("Not a Clique\n");
        else {
            bool yes = true;
            for(int i = 1; i <= N; i++) {
                s.insert(i);
                if(s.size() == v.size()) continue;
                else {
                    v.push_back(i);
                    if(isClique(v)) {
                        yes = false;
                        break;
                    }
                    v.pop_back();
                }
            }
            printf("%s\n", yes ? "Yes": "Not Maximal");
        }
    }
    return 0;
}