#include "iostream"
using namespace std;
// 层中建树
struct node {
    int val;
    node *left, *right;
    node(int v):val(v), left(NULL), right(NULL){}
} *root = NULL;
int level[] = {1, 2, 3, 4, 5};
int in[] = {4, 2, 1, 3, 5};

node* build(int level_left, int level_right, int in_left, int in_right) {
    if(in_left > in_right) return NULL;
    int k, flag = 0;
    while(level_left <= level_right) {
        for(k = in_left; k <= in_right; k++) {
            if(in[k] == level[level_left]) {
                flag = 1;
                break;
            }
        }
        if(flag) break;
        level_left++;
    }
    node* n = new node(in[k]);
    n->left = build(level_left + 1, level_right, in_left, k - 1);
    n->right = build(level_left + 1, level_right, k + 1, right);
    return n;
}

void pre_order(node *n) {
    if(!n) return;
    printf("%d ", n->val);
    pre_order(n->left);
    pre_order(n->right);
}
int main(int argc, char const *argv[])
{
    root = build(0, 4, 0, 4);
    pre_order(root);
    return 0;
}