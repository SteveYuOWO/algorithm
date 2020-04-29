#include "iostream"
#include "vector"
using namespace std;
int N, M;
string l, r;
struct node {
    string data;
    node *left = NULL, *right = NULL;
};
bool judge(node* n1, node* n2) {
    if(n1 == NULL && n2 == NULL) return true;
    else if((n1 == NULL && n2 != NULL) || (n1 != NULL && n2 == NULL)) return false;
    else {
        if(n1->data != n2->data) return false;
        return (judge(n1->left, n2->left) && judge(n1->right, n2->right)) ||
            (judge(n1->left, n2->right) && judge(n1->right, n2->left));
    }
}
int main() {
    cin >> N;
    vector<node> v(N);
    bool root1[99999] = {false}, root2[99999] = {false};
    for(int i = 0; i < N; i++) {
        cin >> v[i].data >> l >> r;
        if(l != "-") {
            v[i].left = &v[stoi(l)];
            root1[stoi(l)] = true;
        }
        if(r != "-") {
            v[i].right = &v[stoi(r)];
            root1[stoi(r)] = true;
        }
    }
    cin >> M;
    vector<node> v2(M);
    for(int i = 0; i < M; i++) {
        cin >> v2[i].data >> l >> r;
        if(l != "-") {
            v2[i].left = &v2[stoi(l)];
            root2[stoi(l)] = true;
        }
        if(r != "-") {
            v2[i].right = &v2[stoi(r)];
            root2[stoi(r)] = true;
        }
    }
    int r1 = -1, r2 = -1;// root
    for(int i = 0; i < N; i++) 
        if(!root1[i]) r1 = i;
    for(int i = 0; i < M; i++) 
        if(!root2[i]) r2 = i;
    if((r1 == -1 && r2 == -1) || judge(&v[r1], &v2[r2])) printf("Yes");
    else printf("No");
    return 0;
}
