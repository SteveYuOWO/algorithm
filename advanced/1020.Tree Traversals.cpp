#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
struct node {
    int data, index, level;
};
int N;
int post[99999], in[99999];
vector<node> v;
void build(int root, int start, int end, int index, int level) {
    if(start > end) return;
    int i = start;
    while(i < end && post[root] != in[i]) i++;
    v.push_back({in[i], index, level});
    build(root - 1 - (end - i), start, i - 1, 2 * index + 1, level + 1);
    build(root - 1, i + 1, end, 2 * index + 2, level + 1);
}
bool cmp(node n1, node n2) {
    if(n1.level != n2.level) return n1.level < n2.level;
    return n1.index < n2.index;
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) 
        scanf("%d", &post[i]);
    for(int i = 0; i < N; i++) 
        scanf("%d", &in[i]);
    build(N - 1, 0, N - 1, 0, 0);
    sort(v.begin(), v.end(), cmp);
    printf("%d", v[0].data);
    for(int i = 1; i < N; i++)
        printf(" %d", v[i].data);
    return 0;
}
