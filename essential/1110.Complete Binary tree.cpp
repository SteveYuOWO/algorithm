#include <iostream>
#include <string>
#include <queue>
using namespace std;
// 考察完全二叉树的判断
struct node {
    int val, left, right;
}n[30];
int N, f[30], m = 0, last; string l, r;
bool judge(int index) {
    queue<int> q;
    bool flag = false;
    q.push(index);
    while(q.size()) {
        node* tmp = &n[q.front()]; q.pop();
        last = tmp->val;
        if(!flag) {
            if(tmp->left != -1 && tmp->right != -1) 
                q.push(tmp->left), q.push(tmp->right);
            else if(tmp->left != -1) q.push(tmp->left), flag = true;
            else if(tmp->right != -1) return false;
            else flag = true;
        } else {
            if(tmp->left != -1 || tmp->right != -1) return false;
        }
    }
    return true;
}
int main() {
    // freopen("in.txt", "r", stdin);
    cin >> N;
    for(int i = 0; i < N; i++) {
        n[i].val = i;
        cin >> l >> r;
        if(l[0] == '-') n[i].left = -1; else n[i].left = stoi(l), f[n[i].left] = 1;
        if(r[0] == '-') n[i].right = -1; else n[i].right = stoi(r), f[n[i].right] = 1;
    }
    while(m < N && f[m]) m++;
    bool j = judge(m);
    if(j) printf("YES %d\n", last);
    else printf("NO %d\n", n[m].val);
    return 0;
}