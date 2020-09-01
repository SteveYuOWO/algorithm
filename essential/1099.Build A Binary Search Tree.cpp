#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
// 板子题之 中序遍历，层序遍历
struct node {
    int val, left, right;
}n[110];
int q[110], N, m = 0;
void inorder(int index) {
    if(n[index].left != -1) inorder(n[index].left);
    n[index].val = q[m++];
    if(n[index].right != -1) inorder(n[index].right);
}
void level(int index) {
    bool start = true;
    queue<int> q;
    q.push(index);
    while(!q.empty()) {
        node *tmp = &n[q.front()]; q.pop();
        if(start) printf("%d", tmp->val), start = false;
        else printf(" %d", tmp->val);
        if(tmp->left != -1) q.push(tmp->left);
        if(tmp->right != -1) q.push(tmp->right);
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d%d", &n[i].left, &n[i].right);
    for(int i = 0; i < N; i++)
        scanf("%d", &q[i]);
    sort(q, q + N);
    inorder(0);
    level(0);
    return 0;
}