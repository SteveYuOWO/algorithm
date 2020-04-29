#include "iostream"
#include "algorithm"
using namespace std;
int M, N, pre[9999], in[9999];
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL) {}
}*root;
node* build(int root, int start, int end) {
    if(start > end) return NULL;
    int i = start;
    while(start < end && pre[root] != in[i]) i++;
    node *n = new node(in[i]);
    n->left = build(root + 1, start, i - 1);
    n->right = build(root + 1 + (i - start), i + 1, end);
    return n;
}
bool dfs(int v, node* root) {
    if(root == NULL) return false;
    else if(v == root->val) return true;
    else return dfs(v, root->left) || dfs(v, root->right);
}
node* lca(node *root, int a, int b) {
    if(root == NULL) return NULL;
    if((root->val - a) * (root->val - b) <= 0) return root;
    else if(root->val < a) return lca(root->right, a, b);
    else return lca(root->left, a, b);
}
int main() {
    scanf("%d%d", &M, &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &pre[i]);
        in[i] = pre[i];
    }
    sort(in, in + N);
    root = build(0, 0, N - 1);
    while(M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        bool find_a = dfs(a, root), find_b = dfs(b, root);
        if(!find_a && !find_b) printf("ERROR: %d and %d are not found.\n", a, b);
        else if(!find_a || !find_b) printf("ERROR: %d is not found.\n", find_a == true ? b: a);
        else {
            node* n = lca(root, a, b);
            if(n->val == a || n->val == b) printf("%d is an ancestor of %d.\n", n->val, n->val == a ? b: a);
            else printf("LCA of %d and %d is %d.\n", a, b, n->val); 
        }
    }
    printf("\n");
    return 0;
}