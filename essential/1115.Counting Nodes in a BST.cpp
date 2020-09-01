#include <iostream>
using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL) {}
}*root;
node* insert(node* n, int val) {
    if(n == NULL) n = new node(val);
    else if(val <= n->val) n->left = insert(n->left, val);
    else n->right = insert(n->right, val);
    return n;
}
int N, tmp, depth[1010], maxdepth = -1;
void dfs(node* root, int deep) {
    depth[deep]++; maxdepth = max(deep, maxdepth);
    if(root->left) dfs(root->left, deep + 1);
    if(root->right) dfs(root->right, deep + 1);
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    while(N--) scanf("%d", &tmp), root = insert(root, tmp);
    dfs(root, 0);
    int a = depth[maxdepth], b = depth[maxdepth - 1];
    printf("%d + %d = %d\n", a, b, a + b);
    return 0;
}