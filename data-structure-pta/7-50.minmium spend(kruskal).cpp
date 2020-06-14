#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9999999
using namespace std;
struct edge {
    int a, b, cost;
    bool operator<(const edge e) const {
        return cost < e.cost;
    }
};
int parent[200] = {};
int findParent(int num) {
    if(parent[num] == num) return num;
    return parent[num] = findParent(parent[num]);
}
void Union(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);
    if(pa != pb) parent[pb] = pa;
}
int main() {
    int N, cnt, a, b, mon, build;
    vector<edge> v;
    scanf("%d", &N);
    cnt = N * (N - 1) / 2;
    // 初始化集合
    for(int i = 0; i < 200; i++)
        parent[i] = i;
    // 读数
    while(cnt--) {
        scanf("%d%d%d%d", &a, &b, &mon, &build);
        if(build) Union(a, b);
        else v.push_back({a, b, mon});
    }
    int sum = 0;
    // Kruskal
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        if(findParent(v[i].a) != findParent(v[i].b)) {
            sum += v[i].cost;
            Union(v[i].a, v[i].b);
        }
    }
    printf("%d", sum);
    return 0;
}
