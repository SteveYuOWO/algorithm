#include <iostream>
#include <stack>
using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL) {}
};
void preorder(node* root) {
    stack<node*> s;
    if(root) s.push(root);
    while(!s.empty()) {
        node* n = s.top(); s.pop();
        printf("%d ", n->val);
        if(n->right) s.push(n->right);
        if(n->left) s.push(n->left);
    }
    putchar('\n');
}
void inorder(node* root) {
    stack<node*> s;
    while(!s.empty() || root != NULL) {
        while(root) {
            s.push(root);
            root = root->left;
        }
        root = s.top(); s.pop();
        printf("%d ", root->val);
        root = root->right;
    }
    putchar('\n');
}
int main() {
    node *n = new node(10);
    n->left = new node(8);
    n->right = new node(12);
    n->left->left = new node(7);
    n->left->right = new node(9);
    n->right->left = new node(11);
    n->right->right = new node(13);
    preorder(n);
    inorder(n);
    return 0;
}