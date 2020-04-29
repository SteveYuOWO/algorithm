#include "iostream"
#include "algorithm"
using namespace std;
int N;
bool bst = true, print_inorder = true;
struct node {
    int label, left = -1, right = -1, index;
}n1[1000], n2[1000];
void dfs(int root, int index) {
    n1[root].label = index;
    if(n1[root].left != -1) dfs(n1[root].left, index * 2 + 1);
    if(n1[root].right != -1) dfs(n1[root].right, index * 2 + 2);
}
bool cmp(node& node1, node& node2) {
    return node1.label < node2.label;
}
void inorder(int root) {
    if(n2[root].left != -1) inorder(n2[root].left);
    if(print_inorder) printf("%d", root);
    else printf(" %d", root);
    print_inorder = false;
    if(n2[root].right != -1) inorder(n2[root].right);
}
int main() {
    string l, r;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        cin >> r >> l;
        if(l[0] != '-') n1[i].left = n2[i].left = stoi(l);
        if(r[0] != '-') n1[i].right = n2[i].right = stoi(r);
        n1[i].index = n2[i].index = i;
    }
    int find_root[1000] = {0}, root_index;
    for(int i = 0; i < N; i++){
        if(n1[i].left != -1) find_root[n1[i].left]++;
        if(n1[i].right != -1) find_root[n1[i].right]++;
    }
    for(int i = 0; i < N; i++) 
        if(!find_root[i]) root_index = i;
    dfs(root_index, 0);
    sort(n1, n1 + N, cmp);
    printf("%d", n1[0].index);
    for(int i = 1; i < N; i++)
        printf(" %d", n1[i].index);
    printf("\n");
    inorder(root_index);
    return 0;
}