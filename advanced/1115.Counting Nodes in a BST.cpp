#include <iostream>
using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int v): val(v), left(NULL), right(NULL) {}
}*root;
int arr[1000] = {0}, max_level = 0;
node* insert(node* root, int data, int level) {
    if(root == NULL) {
        max_level = max(max_level, level);
        arr[level]++;
        root = new node(data);
    }
    else if(data <= root->val) root->left = insert(root->left, data, level + 1);
    else root->right = insert(root->right, data, level + 1);
    return root;
}
int N, tmp;
int main() {
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &tmp);
        root = insert(root, tmp, 0);
    }
    printf("%d + %d = %d\n", arr[max_level], arr[max_level - 1], arr[max_level] + arr[max_level - 1]);
    return 0;
}