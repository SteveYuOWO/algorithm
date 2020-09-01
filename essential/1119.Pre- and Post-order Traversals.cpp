#include <iostream>
using namespace std;
// 前中建树，中序遍历
int N, pre[100], post[100];
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL) {}
}*root;
node* build(int pre_l, int pre_r, int post_l, int post_r) {
    if(pre_l > pre_r) return NULL;
    if(pre_l == pre_r) return new node(pre[pre_l]);
    node *n = new node(pre[pre_l]);
    int i = post_l;
    while(i < post_r && pre[pre_l + 1] != post[i]) i++;
    n->left = build(pre_l + 1, pre_l + 1 + i - post_l, post_l, i - 1);
    n->right = build(pre_l + 1 + i - post_l + 1, pre_r, i + 1, post_r);
    return n;
}
bool dfs(node* root) {
    if(!root) return true;
    else if(root->left && root->right) return dfs(root->left) && dfs(root->right);
    else if(root->left || root->right) return false;
    else return true;
}
bool start = true;
void inorder(node* root) {
    if(root->left) inorder(root->left);
    if(start) printf("%d", root->val), start = false; else printf(" %d", root->val);
    if(root->right) inorder(root->right);
}
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &pre[i]);
    for(int i = 0; i < N; i++) scanf("%d", &post[i]);
    root = build(0, N - 1, 0, N - 1);
    printf("%s\n", dfs(root) ? "Yes": "No");
    inorder(root);
    putchar('\n');
    return 0;
}