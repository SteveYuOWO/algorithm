#include "iostream"
using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int v):val(v), left(NULL), right(NULL) {}
} *root;
// get height
int get_height(node* root) {
    if(!root) return 0;
    return max(get_height(root->left), get_height(root->right)) + 1;
}
// Single Left Rotation
node* single_left_rotation(node* root) {
    node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}
// Single Right Rotation
node* single_right_rotation(node* root) {
    node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}
//  Double Left Right Rotation
node* double_left_right_rotation(node* root) {
    root->left = single_right_rotation(root->left);
    return single_left_rotation(root);
}
// Double Right left Rotation
node* double_right_left_rotation(node* root) {
    root->right = single_left_rotation(root->right);
    return single_right_rotation(root);
}
// insert
node* insert(node* root, int data) {
    if(root == NULL) root = new node(data);
    else if(data < root->val) {
        root->left = insert(root->left, data);
        if(get_height(root->left) - get_height(root->right) == 2) {
            if(data < root->left->val) root = single_left_rotation(root);
            else root = double_left_right_rotation(root); 
        }
    } else {
        root->right = insert(root->right, data);
        if(get_height(root->right) - get_height(root->left) == 2) {
            if(data > root->right->val) root = single_right_rotation(root);
            else root = double_right_left_rotation(root);
        }
    }
    return root;
}
int main() {
    int N, tmp;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &tmp);
        root = insert(root, tmp);
    }
    printf("%d", root->val);
    return 0;
}