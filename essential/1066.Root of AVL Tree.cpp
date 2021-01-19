#include <iostream>
using namespace std;
// AVL
struct node {
    int val;
    node *left, *right;
    node(int v):val(v), left(NULL), right(NULL) {}
}*root;
int getHeight(node* n) {
    if(!n) return 0;
    return max(getHeight(n->left), getHeight(n->right)) + 1;
}
node* LL(node* n) {
    node* t = n->left;
    n->left = t->right;
    t->right = n;
    return t;
}
node* RR(node* n) {
    node* t = n->right;
    n->right = t->left;
    t->left = n;
    return t;
}
node* LR(node* n) {
    n->left = RR(n->left);
    return LL(n);
}
node* RL(node* n) {
    n->right = LL(n->right);
    return RR(n);
}
node* insert(node* n, int data) {
    if(!n) n = new node(data);
    else if(data <= n->val) {
        n->left = insert(n->left, data);
        if(getHeight(n->left) - getHeight(n->right) == 2) {
            if(data < n->left->val) n = LL(n);
            else n = LR(n);
        }
    } else {
        n->right = insert(n->right, data);
        if(getHeight(n->right) - getHeight(n->left) == 2) {
            if(data > n->right->val) n = RR(n);
            else n = RL(n);
        }
    }
    return n;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int N, tmp;
    scanf("%d", &N);
    while(N--) scanf("%d", &tmp), root = insert(root, tmp);
    printf("%d\n", root->val);
    return 0;
}