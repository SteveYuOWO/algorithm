#include <iostream>
using namespace std;
int M, N, in[10100], pre[10100], a, b;
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL){}
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
bool find(node *root, int val) {
    if(!root) return false;
    if(root->val == val) return true;
    return find(root->left, val) || find(root->right, val);
}
node* lca(node *root, int a, int b) {
    if(!root) return NULL;
    if(root->val == a || root->val == b) return root;
    node *l = lca(root->left, a, b);
    node *r = lca(root->right, a, b);
    if(l && r) return root;
    return l == NULL ? r : l;
}
int main() {
    cin >> M >> N;
    for(int i = 0; i < N; i++)
        cin >> in[i];
    for(int i = 0; i < N; i++)
        cin >> pre[i];
    root = build(0, 0, N - 1);
    while(M--) {
        cin >> a >> b;
        bool right_a = find(root, a);
        bool right_b = find(root, b);
        if(right_a && right_b) {
            node *n = lca(root, a, b);
            if(n->val != a && n->val != b) printf("LCA of %d and %d is %d.\n", a, b, n->val);
            else if(n->val == a) printf("%d is an ancestor of %d.\n", a, b);
            else printf("%d is an ancestor of %d.\n", b, a);
        } else {
            if(!right_a && !right_b) printf("ERROR: %d and %d are not found.\n", a, b);
            else if(!right_a) printf("ERROR: %d is not found.\n", a);
            else printf("ERROR: %d is not found.\n", b);
        }
    }
    return 0;
}