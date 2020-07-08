#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int N, M, T, parent, tmp;
vector<vector<int>> all_path;
struct node {
    int weight;
    vector<int> child;
}n[999999];
void dfs(int root, int weight, vector<int> path) {
    path.push_back(n[root].weight);
    weight += n[root].weight;
    if(n[root].child.size() == 0 && weight == T) 
        all_path.push_back(path);
    for(int i = 0; i < n[root].child.size(); i++)
        dfs(n[root].child[i], weight, path);
}
bool cmp(vector<int>& v1, vector<int>& v2) {
    for(int i = 0; i < v1.size(); i++) {
        if(i >= v2.size()) return true;
        if(v1[i] != v2[i]) return v1[i] > v2[i];
    }
    return false;
}
int main() {
    vector<int> path;
    scanf("%d%d%d", &N, &M, &T);
    for(int i = 0; i < N; i++) 
        scanf("%d", &n[i].weight);
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &parent, &tmp);
        n[parent].child.resize(tmp);
        for(int j = 0; j < n[parent].child.size(); j++)
            scanf("%d", &n[parent].child[j]);
    }
    dfs(0, 0, path);
    sort(all_path.begin(), all_path.end(), cmp);
    for(int i = 0; i < all_path.size(); i++) {
        printf("%d", all_path[i][0]);
        for(int j = 1; j < all_path[i].size(); j++)
            printf(" %d", all_path[i][j]);
        printf("\n");
    }
    return 0;
}
