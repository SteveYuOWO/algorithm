#include "iostream"
#include "vector"
using namespace std;
int N, M;
vector<int> in, pre;
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL) {}
}*n;
node* build(int root, int start, int end) {
    if(start > end) return NULL;
    int i = start;
    while (i < end && in[i] != pre[root]) i++;
    node *tmp = new node(in[i]);
    tmp->left = build(root + 1, start, i - 1);
    tmp->right = build(root + 1 + i - start, i + 1, end);
    return tmp;
}
bool find(node* root, int val) {
    if(!root) return false;
    if(root->val == val) return true;
    return find(root->left, val) || find(root->right, val);
}
node* lca(node* root, int val1, int val2) {
    if(!root) return NULL;
    if(root->val == val1 || root->val == val2) return root;
    node* l = lca(root->left, val1, val2);
    node* r = lca(root->right, val1, val2);
    if(l && r) return root;
    return l ? l: r;
}
int main() {
    int N, M, d1, d2;
    scanf("%d%d", &M, &N);
    in.resize(N); pre.resize(N);
    for(int i = 0; i < N; i++) scanf("%d", &in[i]);
    for(int i = 0; i < N; i++) scanf("%d", &pre[i]);
    n = build(0, 0, N - 1);
    while(M--) {
        scanf("%d%d", &d1, &d2);
        if(!find(n, d1) && !find(n, d2)) printf("ERROR: %d and %d are not found.\n", d1, d2);
        else if(!find(n, d1)) printf("ERROR: %d is not found.\n", d1);
        else if(!find(n, d2)) printf("ERROR: %d is not found.\n", d2);
        else {
            int ancestor = lca(n, d1,d2)->val;
            if(ancestor == d1) printf("%d is an ancestor of %d.\n", d1, d2);
            else if(ancestor == d2) printf("%d is an ancestor of %d.\n", d2, d1);
            else printf("LCA of %d and %d is %d.\n", d1, d2, ancestor);
        }
    }
    return 0;
}