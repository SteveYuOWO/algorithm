#include <iostream>
#include <queue>
using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL) {}
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
node* insert(node* n, int val) {
    if(n == NULL) n= new node(val);
    else if(val <= n->val) {
        n->left = insert(n->left, val);
        if(getHeight(n->left) - getHeight(n->right) == 2) {
            if(val < n->left->val) n = LL(n);
            else n = LR(n);
        }
    } else {
        n->right = insert(n->right, val);
        if(getHeight(n->right) - getHeight(n->left) == 2) {
            if(val > n->right->val) n = RR(n);
            else n = RL(n);
        }
    }
    return n;
}
void level(node* n) {
    queue<node*> q;
    q.push(n);
    bool s = true;
    while(q.size()) {
        node* tmp = q.front(); q.pop();
        if(s) printf("%d", tmp->val), s = !s; else printf(" %d", tmp->val);
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
}
bool complete(node* root) {
    if(!root) return true;
    bool flag = true;
    queue<node*> q;
    q.push(root);
    while(q.size()) {
        node* tmp = q.front(); q.pop();
        if(flag) {
            if(tmp->left && tmp->right) q.push(tmp->left), q.push(tmp->right);
            else if(tmp->left) q.push(tmp->left), flag = false;
            else if(tmp->right) return false;
            else flag = false;
        } else {
            if(tmp->left || tmp->right) return false;
        }
    }
    return true;
}
int N, tmp;
int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    while(N--) scanf("%d", &tmp), root = insert(root, tmp);
    level(root);
    putchar('\n');
    printf("%s\n", complete(root) ? "YES": "NO");
    return 0;
}