#include "iostream"
#include "queue"
using namespace std;
struct node {
    int val;
    node *left, *right;
    node(int v):val(v), left(NULL), right(NULL){}
}*root = NULL;
int get_height(node* n) {
    if(n == NULL) return 0;
    return max(get_height(n->left), get_height(n->right)) + 1;
}
node* single_left_rotation(node* n) {
    node* tmp = n->left;
    n->left = tmp->right;
    tmp->right = n;
    return tmp;
}
node* single_right_rotation(node* n) {
    node* tmp = n->right;
    n->right = tmp->left;
    tmp->left = n;
    return tmp;
}
node* double_left_right_rotation(node* n) {
    n->left = single_right_rotation(n->left);
    return single_left_rotation(n);
}
node* double_right_left_rotation(node* n) {
    n->right = single_left_rotation(n->right);
    return single_right_rotation(n);
}
node* insert(node* n, int data) {
    if(n == NULL) {
        n = new node(data);
        return n;
    } else if(data < n->val) {
        n->left = insert(n->left, data);
        if(get_height(n->left) - get_height(n->right) == 2) {
            if(data < n->left->val) n = single_left_rotation(n);
            else n = double_left_right_rotation(n);
        }
    } else {
        n->right = insert(n->right, data);
        if(get_height(n->right) - get_height(n->left) == 2) {
            if(data > n->right->val) n = single_right_rotation(n);
            else n = double_right_left_rotation(n);
        }
    }
    return n;
}
bool start = true;
void level_order_traversal(node* n) {
    if(n == NULL) return;
    queue<node*> que;
    que.push(n);
    while(!que.empty()) {
        node* tmp = que.front();
        que.pop();
        if(start) {
            printf("%d", tmp->val);
            start = !start;
        }else printf(" %d", tmp->val);
        if(tmp->left) que.push(tmp->left);
        if(tmp->right) que.push(tmp->right);
    }
}
bool judge_complete_binary_tree(node* n) {
    if(n == NULL) return false;
    queue<node*> que;
    que.push(n);
    bool flag = false;
    while(!que.empty()) {
        node* tmp = que.front();
        que.pop();
        if(flag) {
            if(tmp->left || tmp->right) return false;
        } else {
            if(tmp->left && tmp->right) {
                que.push(tmp->left);
                que.push(tmp->right);
            } else if(tmp->right) return false;
            else if(tmp->left) {
                que.push(tmp->left);
                flag = true;
            } else flag = true;
        }
    }
    return true;
}
int main() {
    int N, tmp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        root = insert(root, tmp);
    }
    level_order_traversal(root);
    printf("\n%s", judge_complete_binary_tree(root) ? "YES": "NO");
    return 0;
}
