#include "iostream"
using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int v):val(v), left(NULL), right(NULL) {}
};
int N, M, tmp;
node* insert(node* root, int data) {
    if(root == NULL) root = new node(data);
    else if(abs(data) <= abs(root->val)) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}
bool dfs(node* root) {
    if(root == NULL) return true;
    if(root->val < 0) {
        if(root->left != NULL && root->left->val < 0) return false;
        if(root->right != NULL && root->right->val < 0) return false;
    }
    return dfs(root->left) && dfs(root->right);
}
int get_num(node *root) {
    if(root == NULL) return 0;
    int ans = max(get_num(root->left), get_num(root->right));
    return root->val > 0 ? ans + 1: ans;
}
bool dfs2(node* root) {
    if(root == NULL) return true;
    return get_num(root->left) == get_num(root->right) 
            && dfs2(root->left) && dfs2(root->right);
}
int main() {
    scanf("%d ", &N);
    while(N--) {
        scanf("%d", &M);
        node *root = NULL;
        for(int i = 0; i < M; i++) {
            scanf("%d", &tmp);
            root = insert(root, tmp);
        }
        if(dfs2(root) && dfs(root) && root->val >= 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}