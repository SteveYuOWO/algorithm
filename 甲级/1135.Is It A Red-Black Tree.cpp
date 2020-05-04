#include <iostream>
using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL) {}
};
node* insert(node *n, int v) {
    if(!n) return new node(v);
    else if(abs(n->val) < abs(v)) n->left = insert(n->left, v);
    else n->right = insert(n->right, v);
    return n;
}
bool judge = true; 
int black = -1;
void dfs(node *root, int blacknum) {
    if(!root) {
        if(black == -1) black = blacknum;
        else if(black != blacknum) judge = false;
        return;
    }
    if(root->val > 0) blacknum++;
    if(root->left && root->val < 0 && root->left->val < 0) judge = false;
    if(root->right && root->val < 0 && root->right->val < 0) judge = false;
    dfs(root->left, blacknum);
    dfs(root->right, blacknum);
}
int main() {
    int N, K, v;
    cin >> N;
    while(N--) {
        cin >> K;
        node *root = NULL;
        judge = true;
        black = -1;
        while(K--) {
            cin >> v;
            root = insert(root, v);
        }
        if(root->val < 0) judge = false; 
        dfs(root, 0);
        if(judge) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}