#include "iostream"
#include "set"
#include "vector"
using namespace std;
int N, a, b;
bool path[10100][10100] = {false};
bool vis[10100] = {false};
int max_height = -1;
set<int> s;
vector<int> vec;
void dfs(int v, int height) {
    vis[v] = true;
    if(height > max_height) {
        max_height = height;
        vec.clear();
        vec.push_back(v);
    }else if(height == max_height) vec.push_back(v);
    for(int i = 1; i <= N; i++) 
        if(path[v][i] && !vis[i])
            dfs(i, height + 1);
}
int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N - 1; i++) {
        scanf("%d%d", &a, &b);
        path[a][b] = true;
        path[b][a] = true;
    }
    int components = 0;
    // find components
    for(int i = 1; i <= N; i++) {
        if(vis[i] == false) {
            dfs(i, 1);
            components++;
        }
    }
    if(components > 1) 
        printf("Error: %d components\n", components);
    else {
        // find max
        max_height = 0;
        fill(vis, vis + N + 10, false);
        for(auto x: vec) s.insert(x);
        dfs(vec[0], 1);
        for(auto x: vec) s.insert(x);
        for(auto x: s) printf("%d\n", x);
    }
    return 0;
}