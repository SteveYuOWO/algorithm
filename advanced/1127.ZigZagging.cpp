#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int d): data(d), left(NULL), right(NULL) {}
}*root;
int N, in[99999], post[99999], maxLevel = -1;
node* build(int root, int start, int end) {
    if(start > end) return NULL;
    int i = start;
    while(i < end && in[i] != post[root]) i++;
    node *n = new node(in[i]);
    n->left = build(root - 1 - (end - i), start, i - 1);
    n->right = build(root - 1, i + 1, end);
    return n;
}
vector<node*> v[99999], ans;
void level(node *root) {
    queue<pair<node*, int>> que;
    que.push({root, 0});
    while(!que.empty()) {
        pair<node*, int> n = que.front();
        v[n.second].push_back(n.first);
        maxLevel = max(maxLevel, n.second);
        que.pop();
        if(n.first->left) que.push({n.first->left, n.second + 1});
        if(n.first->right) que.push({n.first->right, n.second + 1});
    }
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &post[i]);
    root = build(N - 1, 0, N - 1);
    level(root);
    for(int i = 0; i <= maxLevel; i++) {
        if(i % 2 == 0) {
            for(int j = v[i].size() - 1; j >= 0; j--) 
                ans.push_back(v[i][j]);
        } else {
            for(int j = 0; j < v[i].size(); j++) 
                ans.push_back(v[i][j]);
        }
    }
    printf("%d", ans[0]->data);
    for(int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]->data);
    return 0;
}