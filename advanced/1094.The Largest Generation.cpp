#include "iostream"
#include "vector"
#include "map"
using namespace std;
int N, M, parent, tmp_num;
struct node {
    int level = -1;
    vector<int> child;
}n[999999];
void dfs(int root, int level) {
    n[root].level = level;
    for(int i = 0; i < n[root].child.size(); i++) 
        dfs(n[root].child[i], level + 1);
}
map<int, int> m;
int main() {
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d", &parent, &tmp_num);
        n[parent].child.resize(tmp_num);
        for(int i = 0; i < tmp_num; i++) 
            scanf("%d", &n[parent].child[i]);
    }
    dfs(1, 1);
    for(int i = 1; i <= N; i++)
        if(n[i].level != -1) m[n[i].level]++;
    int mk = -1, mv = -1;
    for(auto it = m.begin(); it != m.end(); it++)
        if(it->second > mv) {
            mv = it->second;
            mk = it->first;
        }
    printf("%d %d", mv, mk);
    return 0;
}
