#include <iostream>
using namespace std;
int N, index_in = 0, uniq = true;
int pre[99999], post[99999], in[99999];
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL){}
}*root;
node *build(int pre_l, int pre_r, int post_l, int post_r) {
    if(pre_l > pre_r) return NULL;
    if(pre_l == pre_r) return new node(pre[pre_l]);
    node *n = new node(pre[pre_l]);
    int k = post_l;
    while(k < post_r && post[k] != pre[pre_l + 1]) k++;
    n->left = build(pre_l + 1, pre_l + 1 + k - post_l, post_l , k);
    n->right = build(pre_l + 1 + k - post_l + 1, pre_r, k + 1, post_r - 1);
    return n;
}
void inorder(node *n) {
    if(!n) return;
    if((n->left && !n->right) || (n->right && !n->left)) uniq = false;
    inorder(n->left);
    in[index_in++] = n->val;
    inorder(n->right);
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", pre + i);
    for(int i = 0; i < N; i++)
        scanf("%d", post + i);
    root = build(0, N-1, 0, N-1);
    inorder(root);
    printf("%s\n%d", uniq ? "Yes":"No", in[0]);
    for(int i = 1; i < N; i++)
        printf(" %d", in[i]);
    putchar('\n');
    return 0;
}