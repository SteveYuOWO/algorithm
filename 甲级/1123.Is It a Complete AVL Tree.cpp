#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int d):data(d), left(NULL), right(NULL) {}
}*root = NULL;
int getHeight(node* n) {
    if(n == NULL) return 0;
    return max(getHeight(n->left), getHeight(n->right)) + 1;
}
node* singleLeftRotation(node* root) {
    node* t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node* singleRightRotation(node* root) {
    node* t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
node* doubleLeftRightRotation(node* root) {
    root->left = singleRightRotation(root->left);
    return singleLeftRotation(root);
}
node* doubleRightLeftRotation(node* root) {
    root->right = singleLeftRotation(root->right);
    return singleRightRotation(root);
}
node* insert(node* root, int v) {
    if(root == NULL) root = new node(v);
    else if(v > root->data) {
        root->right = insert(root->right, v);
        if(getHeight(root->right) - getHeight(root->left) == 2) {
            if(v > root->right->data) root = singleRightRotation(root);
            else root = doubleRightLeftRotation(root);
        }
    } else {
        root->left = insert(root->left, v);
        if(getHeight(root->left) - getHeight(root->right) == 2) {
            if(v < root->left->data) root = singleLeftRotation(root);
            else root = doubleLeftRightRotation(root);
        }
    }
    return root;
}
vector<int> ans;
bool level(node* root) {
    queue<node*> que;
    que.push(root);
    bool flag = true, judge = true;
    while(!que.empty()) {
        node* tmp = que.front();
        que.pop();
        ans.push_back(tmp->data);
        if(tmp->left) que.push(tmp->left);
        if(tmp->right) que.push(tmp->right);
        if(flag) {
            if((!tmp->right && tmp->left) || (!tmp->left && !tmp->right)) flag = false;
            else if(!tmp->left && tmp->right) judge = false;
        } else if(tmp->left || tmp->right) judge = false;
    }
    return judge;
}
int main() {
    int N, val;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    bool judge = level(root);
    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++) 
        printf(" %d", ans[i]);
    printf("\n%s\n", judge ? "YES": "NO");
    return 0;
}