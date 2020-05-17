#include "iostream"
#include "vector"
#include "string"
#include "queue"
using namespace std;
int N;
string tmp_l, tmp_r;
struct node {
    int data, left = -1, right = -1, level;
};
vector<node> v;
void levelorder(int root) {
    bool start = true;
    queue<node> que;
    que.push(v[root]);
    while(!que.empty()) {
        node n = que.front();
        if(start) {
            printf("%d", n.data);
            start = false;
        } else printf(" %d", n.data);
        que.pop();
        if(n.left != -1) que.push(v[n.left]);
        if(n.right != -1) que.push(v[n.right]);
    }
}      
bool start = true;
void inorder(int root) {
    if(v[root].left != -1) inorder(v[root].left);
    if(start) {
        start = !start;
        printf("%d", v[root].data);
    } else printf(" %d", v[root].data);
    if(v[root].right != -1) inorder(v[root].right);
}
int main() {
    scanf("%d", &N);
    v.resize(N);
    vector<bool> judge(N, false);
    for(int i = 0;i < N; i++) {
        cin >> tmp_l >> tmp_r;
        v[i].data = i;
        if(tmp_l != "-") {
            v[i].right = stoi(tmp_l);
            judge[stoi(tmp_l)] = true;
        }
        if(tmp_r != "-") {
            v[i].left = stoi(tmp_r);
            judge[stoi(tmp_r)] = true;
        }
    }
    int root_index;
    for(int i = 0; i < N; i++)
        if(judge[i] == false) root_index = i;
    levelorder(root_index);
    putchar('\n');
    inorder(root_index);
    return 0;
}
