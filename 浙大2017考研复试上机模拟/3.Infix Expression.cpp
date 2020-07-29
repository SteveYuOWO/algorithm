#include <iostream>
using namespace std;
struct node {
    string val;
    node *left = NULL, *right = NULL;
}n[999999];
string dfs(node* root) {
    if(root->left && root->right) 
        return "(" + dfs(root->left) + root->val + dfs(root->right) + ")";
    else if(root->right)
        return "(" + root->val + dfs(root->right) + ")";
    return root->val;
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int N, l , r;
    string s;
    cin >> N;
    bool find[999999] = {false};
    for(int i = 1; i <= N; i++) {
        cin >> s >> l >> r;
        n[i].val = s; 
        if(l != -1) n[i].left = &n[l]; 
        if(r != -1) n[i].right = &n[r];
        find[l] = find[r] = true;
    }
    int root = 1;
    while(find[root]) root++;
    string ans = dfs(&n[root]);
    if(ans[0] == '(')  ans = ans.substr(1, ans.size() - 2);
    cout << ans;
    return 0;
}
