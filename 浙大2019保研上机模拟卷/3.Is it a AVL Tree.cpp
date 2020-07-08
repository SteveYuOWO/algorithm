#include <iostream>
#include <vector>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int d): data(d), left(NULL), right(NULL) {}
};
node* insert(node* n, int data) {
    if(n == NULL) n = new node(data);
    else if(data < n->data) n->left = insert(n->left, data);
    else n->right = insert(n->right, data);
    return n;
}
int getHeight(node* n) {
    if(n == NULL) return 0;
    return max(getHeight(n->left), getHeight(n->right)) + 1;
}
bool judgeAVL(node* n) {
    if(n == NULL) return true;
    if(abs(getHeight(n->left) - getHeight(n->right)) > 1) return false;
    return judgeAVL(n->left) && judgeAVL(n->right);
}
int main() {
    int K, N, tmp;
    scanf("%d", &K);
    while(K--) {
        scanf("%d", &N);
        node *n = NULL;
        for(int i = 0; i < N; i++) {
            scanf("%d", &tmp);
            n = insert(n, tmp);
        }
        printf("%s\n", judgeAVL(n) ? "Yes": "No");
    }
    return 0;
}
