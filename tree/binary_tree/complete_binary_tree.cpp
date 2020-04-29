#include "iostream"
#include "vector"
#include "queue"
using namespace std;
int N, root, tail;
struct node {
    int left = -1, right = -1;
};
vector<node> v;
bool judge_complete_binary_tree(int root) {
    queue<int> que;
    que.push(root);
    bool flag = false, ans = true;
    while(!que.empty()) {
        int tmp = que.front();
        tail = tmp;
        que.pop();
        if(flag) {
            if(v[tmp].left != -1 || v[tmp].right != -1) ans = false;
        }
        else {
            if(v[tmp].left != -1 && v[tmp].right != -1) {
                que.push(v[tmp].left);
                que.push(v[tmp].right);
            } else if(v[tmp].left != -1) {
                que.push(v[tmp].left);
                flag = true;
            } else if(v[tmp].right != -1) ans = false;
            else flag = true;
        }
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    string tmp1, tmp2;
    cin >> N;
    v.resize(N);
    vector<bool> find_root(N, 1);
    for(int i = 0; i < N; i++) {
        cin >> tmp1 >> tmp2;
        if(tmp1 != "-") {
            v[i].left = stoi(tmp1);
            find_root[stoi(tmp1)] = 0;
        }
        if(tmp2 != "-") {
            v[i].right = stoi(tmp2);
            find_root[stoi(tmp2)] = 0;
        }
    }
    for(int i = 0; i < N; i++) 
        if(find_root[i]) root = i;
    if(judge_complete_binary_tree(root))  printf("YES %d", tail);
    else printf("NO %d", root);
    return 0;
}
