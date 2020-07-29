#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int N, M, K;
char fro[5], to[5];
unordered_map<string, unordered_set<int>> line;
unordered_map<int, unordered_set<string>> findline;
unordered_map<string, unordered_map<string, int>> G;
unordered_map<string, bool> vis;
vector<string> ans;
int hascommon(unordered_set<int>& s1, unordered_set<int>& s2) {
    for(auto& x: s1) 
        for(auto& y: s2) 
            if(x == y) return x;
    return false;
}
int getTransfer(vector<string> path) {
    int cnt = 0;
    for(int i = 1; i < path.size(); i++)
        if(hascommon(line[path[i - 1]],line[path[i]])) cnt++;
    return cnt;
}
void dfs(string pos, vector<string> path) {
    if(strcmp(pos.c_str(), to) == 0) {
        path.push_back(pos);
        if(path.size() < ans.size() || ans.size() == 0) {
            ans = path;
        } else if(path.size() == ans.size()) {
            if(getTransfer(path) < getTransfer(ans)) 
                ans = path;
        }
        return;
    }
    path.push_back(pos);
    for(auto& x: G[pos]) {
        if(!vis[x.first] && x.second) {
            vis[x.first] = true;
            dfs(x.first, path);
            vis[x.first] = false;
        }
    }
    path.pop_back();
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d%s", &M, fro);
        line[fro].insert(i);
        findline[i].insert(fro);
        for(int j = 1; j < M; j++) {
            scanf("%s", to);
            line[to].insert(i);
            findline[i].insert(to);
            G[fro][to] = G[to][fro] = 1;
            strcpy(fro, to);
        }
    }
    scanf("%d", &K);
    while(K--) {
        scanf("%s%s", fro, to);
        vector<string> path;
        vis[fro] = true;
        dfs(fro, path);
        printf("%lu\n", ans.size() - 1);
        string beg = ans[0], end;
        for(int i = 1; i < ans.size(); i++) {
            if(!hascommon(line[ans[i - 1]], line[ans[i]])) {
                printf("Take Line#%d from %s to %s.\n", hascommon(line[beg], line[ans[i - 1]]), beg.c_str(), ans[i - 1].c_str());
                beg = ans[i - 1];
            }
        }
        printf("Take Line#%d from %s to %s.\n", hascommon(line[beg], line[ans[ans.size() - 1]]), beg.c_str(), ans[ans.size() - 1].c_str());
        ans.clear();
    }
    
    return 0;
}
