#include <iostream>
#include <vector>
using namespace std;
int N, root, cnt = 0; double P, R, ans = 0;
struct node {
    int data;
    vector<int> child;
};
vector<node> tree;
void dfs(int root, double price) {
    if(tree[root].child.size() == 0) {
        if(price > ans) {
            ans = price;
            cnt = 1;
        } else if(price == ans){
            cnt++;
        }
    } else {
        double next = price * (1 + 0.01 * R);
        for(int i = 0; i < tree[root].child.size(); i++) {
            dfs(tree[root].child[i], next);
        }
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%lf%lf", &N, &P, &R);
    tree.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tree[i].data);
        if(tree[i].data != -1) {
            tree[tree[i].data].child.push_back(i);
        } else root = i;
    }
    dfs(root, P);
    printf("%.2f %d", ans, cnt);
    return 0;
}