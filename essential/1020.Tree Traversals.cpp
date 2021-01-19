#include <iostream>
#include <queue>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int d): data(d), left(NULL), right(NULL) {}
}*root;
int N, in[50], post[50];
node* build(int index, int start, int end) {
    if(start > end) return NULL;
    int k = start;
    while(k < end && in[k] != post[index]) k++;
    node *n = new node(in[k]);
    n->left = build(index - 1 - (end - k), start, k - 1);
    n->right = build(index - 1, k + 1, end);
    return n;
}
void level(node *n) {
    bool s = true;
    queue<node*> q;
    q.push(n);
    while(q.size()) {
        node *tmp = q.front(); q.pop();
        if(s) s = !s, printf("%d", tmp->data); else printf(" %d", tmp->data);
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
    putchar('\n');
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &post[i]);
    for(int i = 0; i < N; i++) scanf("%d", &in[i]);
    root = build(N - 1, 0, N - 1);
    level(root);
    return 0;
}