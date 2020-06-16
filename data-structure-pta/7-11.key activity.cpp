#include <iostream>
#include <vector>
#include <set>
using namespace std;
int N, M, a, b, t, digree[110] = {}, G[110][110], maxTime = -1;
vector<int> path[110];
set<pair<int, int>> ans;
void dfs(vector<int> v, int n, int totalTime) {
    if(path[n].size() == 0) {
        if(totalTime > maxTime) {
            maxTime = totalTime;
            ans.clear();
            for(int i = 1; i < v.size(); i++)
                ans.insert({v[i-1], v[i]});
        } else if(totalTime == maxTime) {
            for(int i = 1; i < v.size(); i++)
                ans.insert({v[i-1], v[i]});
        }
        return;
    }
    for(int i = 0; i < path[n].size(); i++) {
        v.push_back(path[n][i]);
        dfs(v, path[n][i], totalTime + G[n][path[n][i]]);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d%d", &a, &b, &t);
        G[a][b] = t;
        path[a].push_back(b);
        digree[b]++;
    }
    for(int i = 1; i <= N; i++) {
        if(digree[i] == 0) {
            vector<int> tmp;
            tmp.push_back(i);
            dfs(tmp, i, 0);
        }
    }
    printf("%d\n", maxTime);
    for(auto& x: ans) 
        printf("%d->%d\n", x.first, x.second);
    return 0;
}
