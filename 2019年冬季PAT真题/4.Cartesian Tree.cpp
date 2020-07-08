#include <iostream>
#include <queue>
using namespace std;
int N, tmp, arr[99999];
struct node {
    int data;
    node *left, *right;
    node(int d): data(d), left(NULL), right(NULL) {}
}*root;
node* build(int l, int r) {
    if(l > r) return NULL;
    int k = l;
    for(int i = l; i <= r; i++) 
        if(arr[k] > arr[i]) k = i;
    node *n = new node(arr[k]);
    n->left = build(l, k - 1);
    n->right = build(k + 1, r);
    return n;
}
void levelOrder(node *n) {
    queue<node*> q;
    q.push(n);
    bool start = true;
    while(!q.empty()) {
        node *n = q.front();
        q.pop();
        if(start) {
            start = !start;
            printf("%d", n->data);
        } else printf(" %d", n->data);
        if(n->left) q.push(n->left);
        if(n->right) q.push(n->right);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) 
        scanf("%d", &arr[i]);
    root = build(0, N-1);
    levelOrder(root);
    return 0;
}
