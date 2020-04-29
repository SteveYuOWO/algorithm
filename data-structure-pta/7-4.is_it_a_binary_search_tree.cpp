#include "iostream"
#include "vector"
using namespace std;
int N, L, tmp;
struct node {
    int data;
    node *left, *right;
    node(int d):data(d), left(NULL), right(NULL){}
} *n1, *n2;
node* insert(node* n, int data) {
    if(n == NULL) n = new node(data);
    else if(n->data < data) n->right = insert(n->right, data);
    else n->left = insert(n->left, data);
    return n;
}
bool dfs(node* n1, node* n2) {
    if(n1 == NULL && n2 == NULL) return true;
    else if((n1 == NULL && n2 != NULL) || (n1 != NULL && n2 == NULL)) return false;
    return dfs(n1->left, n2->left) && dfs(n1->right, n2->right);
}
void pre(node* n) {
    if(n== NULL) return ;
    cout << n->data << " ";
    pre(n->left);
    pre(n->right);
}
int main() {
    while(1) {
        scanf("%d", &N);
        if(N == 0) break;
        scanf("%d", &L);
        n1 = NULL;
        for(int i = 0; i < N; i++) {
            scanf("%d", &tmp);
            n1 = insert(n1, tmp);
        }
        while(L--) {
            n2 = NULL;
            for(int i = 0; i < N; i++) {
                scanf("%d", &tmp);
                n2 = insert(n2, tmp);
            }
            if(dfs(n1, n2)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
