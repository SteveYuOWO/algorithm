#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int N, res_index = 0;
struct node {
    int val, left, right, level;
};
vector<int> in;
vector<node> v;
void inorder(int index, int level) {
    if(index > N) return;
    if(v[index].left != -1) inorder(v[index].left, level + 1);
    v[index].val = in[res_index++];
    v[index].level = level;
    if(v[index].right != -1) inorder(v[index].right, level + 1);
}
bool cmp(node& n1, node& n2) {
    return n1.level == n2.level ? n1.val < n2.val : n1.level < n2.level;
}
int main() {
    scanf("%d", &N);
    v.resize(N); in.resize(N);
    for(int i = 0; i < N; i++) 
        scanf("%d%d", &v[i].left, &v[i].right);
    for(int i = 0; i < N; i++) 
        scanf("%d", &in[i]);
    sort(in.begin(), in.end());
    inorder(0, 0);
    sort(v.begin(), v.end(), cmp);
    printf("%d", v[0].val);
    for(int i = 1; i < N; i++)
        printf(" %d", v[i].val);
    return 0;
}