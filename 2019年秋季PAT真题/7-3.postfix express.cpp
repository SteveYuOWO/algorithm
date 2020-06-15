#include <iostream>
#include <vector>
using namespace std;
struct node {
    string data;
    int left, right;
};
int N, root_index = 1;
vector<node> v;
string dfs(int root) {
    if(root == -1) return "";
    if(v[root].left == -1 && v[root].right != -1) 
        v[root].data = "(" + v[root].data + dfs(v[root].right) + ")" ;
    else v[root].data = "(" + dfs(v[root].left) + dfs(v[root].right) + v[root].data + ")" ;
    return v[root].data;
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
    while(judge[root_index]) root_index++;
    printf("%s", dfs(root_index).c_str());
    return 0;
}