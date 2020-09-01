#include <iostream>
#include <queue>
// 考察 层序，中序遍历
using namespace std;
struct node {
    int val, left, right;
}n[20];
int N, q[20] = {}, m = 0; string l, r;
void levelorder(int index) {
    bool start = true;
    queue<int> q;
    q.push(index);
    while(q.size()) {
        node* tmp = &n[q.front()]; q.pop();
        if(start) printf("%d", tmp->val), start = false;
        else printf(" %d", tmp->val);
        if(tmp->left != -1) q.push(tmp->left);
        if(tmp->right != -1) q.push(tmp->right);
    }
    putchar('\n');
}
bool start = true;
void inorder(int index) {
    if(n[index].left != -1) inorder(n[index].left);
    if(start) printf("%d", n[index].val), start = false;
    else printf(" %d", n[index].val);
    if(n[index].right != -1)inorder(n[index].right);
}
int main() {
    freopen("in.txt", "r", stdin);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> r >> l;
        n[i].val = i;
        if(l[0] == '-') n[i].left = -1; 
        else n[i].left = l[0] - '0', q[n[i].left] = 1;
        if(r[0] == '-') n[i].right = -1; 
        else n[i].right = r[0] - '0', q[n[i].right] = 1;
    }
    while(m < N && q[m]) m++;
    levelorder(m);
    inorder(m);
    cout << endl;
    return 0;
}