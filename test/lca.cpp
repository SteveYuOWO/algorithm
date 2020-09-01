#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
int M, N, pre[10100], in[10100], a, b;
unordered_set<int> s;
struct node {
    int val;
    node *l, *r;
    node(int v):val(v), l(NULL), r(NULL) {}
}*n;
node* build(int u, int l, int r) {
    if(l > r) return NULL;
    node* n = new node(pre[u]);
    int i = l;
    while(l < r && pre[u] != in[i]) i++;
    n->l = build(u + 1, l, i - 1);
    n->r = build(u + 1 + (i - l), i + 1, r);
    return n;
}
node* lca(int a, int b, node* n) {
    if(!n) return NULL;
    int x = n->val;
    if((x - a) * (x - b) <= 0) return n;
    else if(x < a && x < b) return lca(a, b, n->r);
    else return lca(a, b, n->l);
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &M, &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &pre[i]), in[i] = pre[i], s.insert(pre[i]);
    sort(in, in + N);
    n = build(0, 0, N - 1);
    while(M--) {
        scanf("%d%d", &a, &b);
        auto fa = s.find(a), fb = s.find(b);
        if(fa == s.end() && fb == s.end()) printf("ERROR: %d and %d are not found.\n", a, b);
        else if(fa == s.end()) printf("ERROR: %d is not found.\n", a);
        else if(fb == s.end()) printf("ERROR: %d is not found.\n", b);
        else {
            int x = lca(a, b, n)->val;
            if(x != a && x != b) printf("LCA of %d and %d is %d.\n", a, b, x);
            else if(x == a) printf("%d is an ancestor of %d.\n", x, b);
            else printf("%d is an ancestor of %d.\n", x, a);
        }
    }
    return 0;
}