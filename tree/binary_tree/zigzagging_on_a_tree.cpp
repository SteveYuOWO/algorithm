#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
using namespace std;
int N;
struct node {
    int val, index, level;
};
vector<int> in, post;
vector<node> zig;
void build(int root, int start, int end, int index, int level) {
    if(start > end) return;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    zig.push_back({in[i], index, level});
    build(root - 1 - (end - i), start, i - 1, 2 * index + 1, level + 1);
    build(root - 1, i + 1, end, 2 * index + 2, level + 1);
}
bool cmp(node& n1, node& n2) {
    return n1.level == n2.level ? n1.index < n2.index : n1.level < n2.level;
}
int main() {
    scanf("%d", &N);
    in.resize(N); post.resize(N);
    for(int i = 0; i < N; i++) scanf("%d", &in[i]);
    for(int i = 0; i < N; i++) scanf("%d", &post[i]);
    build(N - 1, 0, N - 1, 0, 0);
    sort(zig.begin(), zig.end(), cmp);
    map<int, vector<int>> m;
    for(int i = 0; i < zig.size(); i++)
        m[zig[i].level].push_back(zig[i].val);
    for(auto it = m.begin(); it != m.end(); it++) 
        if(it->first % 2 == 0) reverse(it->second.begin(), it->second.end());
    bool start = true;
    for(auto it = m.begin(); it != m.end(); it++) 
        for(int i = 0; i < it->second.size(); i++)
            if(start) {
                start = false;
                printf("%d", it->second[i]);
            } else printf(" %d", it->second[i]);
    return 0;
}