#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int M, N, a, b;
int pre[11000], in[11000];
map<int, bool> m;
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL) {}
}*root;
node* build(int root, int start, int end) {
    if(start > end) return NULL;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    node *n = new node(in[i]);
    n->left = build(root + 1, start, i - 1);
    n->right = build(root + 1 + (i - start), i + 1, end);
    return n;
}
node* lca(node *root, int a, int b) {
    if(root->val < a && root->val < b) return lca(root->right, a, b);
    if(root->val > a && root->val > b) return lca(root->left, a, b);
    return root;
}
int main() {
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        cin >> pre[i];
        in[i] = pre[i];
        m[pre[i]] = 1;
    }
    sort(in, in + N);
    root = build(0, 0, N - 1);
    while(M--) {
        cin >> a >> b;
        if(m[a] && m[b]) {
            node *n = lca(root, a, b);
            if(n -> val == a) printf("%d is an ancestor of %d.\n", a, b);
            else if(n -> val == b) printf("%d is an ancestor of %d.\n", b, a);
            else printf("LCA of %d and %d is %d.\n", a, b, n->val);
        } else if(!m[a] && !m[b]) printf("ERROR: %d and %d are not found.\n", a, b);
        else if(!m[a]) printf("ERROR: %d is not found.\n", a);
        else printf("ERROR: %d is not found.\n", b);
    }
    return 0;
}