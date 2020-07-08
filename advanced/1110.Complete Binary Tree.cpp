#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
    int v;
    string left, right;
}n[30];
int N, root = 0, last;
bool isComplete(int root) {
    queue<int> que;
    que.push(root);
    bool flag = 1, ret = true;
    while(!que.empty()) {
        node tmp = n[que.front()];
        que.pop();
        last = tmp.v;
        if(tmp.left != "-") que.push(stoi(tmp.left));
        if(tmp.right != "-") que.push(stoi(tmp.right));
        if(flag) {
            if(tmp.left != "-" && tmp.right != "-") {
            } else if(tmp.left != "-") {
                flag = 0;
            } else if(tmp.right != "-") {
                ret = false;
            } else {
                flag = 0;
            }
        } else {
            if(tmp.left != "-" || tmp.right != "-") ret = false;
        }
    }
    return ret;
}
int main() {
    cin >> N;
    vector<int> find_root(N, 0);
    for(int i = 0; i < N; i++) {
        n[i].v = i;
        cin >> n[i].left >> n[i].right;
        if(n[i].left != "-") find_root[stoi(n[i].left)] = 1;
        if(n[i].right != "-") find_root[stoi(n[i].right)] = 1;
    }
    while(root < N && find_root[root]) root++;
    bool complete = isComplete(root);
    printf("%s %d\n", complete ? "YES": "NO", complete ? last: root);
    return 0;
}