#include "iostream"
#include "vector"
using namespace std;
struct node {
    int level;
    vector<int> child;
}n[100];
int m[100] = {0}, max_level = 0;
int N, M, parent, tmp;
void dfs(int root, int level) {
    n[root].level = level;
    if(n[root].child.size() == 0) {
        m[level]++;
        max_level = max(max_level, level);
    }
    for(int i = 0; i < n[root].child.size(); i++) 
        dfs(n[root].child[i], level + 1);
}
int main() {
    scanf("%d%d", &N, &M);
    for(int i  = 0; i < M; i++) {
        scanf("%d%d", &parent, &tmp);
        n[parent].child.resize(tmp);
        for(int j = 0; j < tmp; j++)
            scanf("%d", &n[parent].child[j]);
    }
    dfs(1, 1);
    printf("%d", m[1]);
    for(int i = 2; i <= max_level; i++)
        printf(" %d", m[i]);
    return 0;
}