#include <iostream>
#include <vector>
using namespace std;
int N, root;
struct node {
    string data;
    int left = -1, right = -1;
}*tree = NULL;
vector<node> v;
string dfs(int n) {
    if(n == -1) return "";
    if(v[n].right != -1) {
        v[n].data =  dfs(v[n].left) + v[n].data + dfs(v[n].right);
        if(n != root) v[n].data = '(' + v[n].data + ')';
    }
    return v[n].data;
}
int main() {
    cin >> N;
    v.resize(N + 1);
    vector<bool> judge(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> v[i].data >> v[i].left >> v[i].right;
        if(v[i].left != -1) judge[v[i].left] = 1;
        if(v[i].right != -1) judge[v[i].right] = 1;
    }
    for(int i = 1; i <= N; i++)
        if(!judge[i]) root = i;
    string ans = dfs(root);
    printf("%s", ans.c_str());
    return 0;
}