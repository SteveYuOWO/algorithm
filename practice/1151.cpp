#include <iostream>
#include <unordered_map>
using namespace std;
int M, N, in[10100], pre[10100], a, b;
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL) {}
};
node* build(int u, int l, int r) {
    if(l > r) return NULL;
    int i = l;
    while(i <= r && pre[u] != in[i]) i++;
    node* n = new node(in[i]);
    n->left = build(u + 1, l, i - 1);
    n->right = build(u + 1 + (i - l), i + 1, r);
    return n;
}
node* lca(int a, int b, node* n) {
    if(!n) return NULL;
    if(n->val == a) return n;
    if(n->val == b) return n;
    node* l = lca(a, b, n->left); 
    node* r = lca(a, b, n->right); 
    if(l && r) return n;
    if(l) return l;
    return r; 
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &M, &N);
    unordered_map<int, bool> m;
    for(int i = 0; i < N; i++) scanf("%d", &in[i]), m[in[i]] = 1;
    for(int i = 0; i < N; i++) scanf("%d", &pre[i]);
    node *n = build(0, 0, N - 1);
    while(M--) {
        scanf("%d%d", &a, &b);
        if(!m[a] && !m[b]) printf("ERROR: %d and %d are not found.\n", a, b);
        else if(!m[a]) printf("ERROR: %d is not found.\n", a);
        else if(!m[b]) printf("ERROR: %d is not found.\n", b);
        else {
            node* ans = lca(a, b, n);
            if(ans->val == a) printf("%d is an ancestor of %d.\n", ans->val, b);
            else if(ans->val == b) printf("%d is an ancestor of %d.\n", ans->val, a);
            else printf("LCA of %d and %d is %d.\n", a, b, ans->val);
        }
    }
    return 0;
}