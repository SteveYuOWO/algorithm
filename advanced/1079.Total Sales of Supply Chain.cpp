#include "iostream"
#include "vector"
using namespace std;
int N, tmp;
double P, R, ans = 0;
struct node {
    int val = -1;
    double price;
    vector<int> child;
}n[999999];
void dfs(int root, double price) {
    n[root].price = price * (1.0 + R / 100.0);
    if(n[root].val != -1) ans += (price * n[root].val); 
    for(int i = 0; i < n[root].child.size(); i++)
        dfs(n[root].child[i], n[root].price);
}
int main() {
    scanf("%d%lf%lf", &N, &P, &R);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if(tmp == 0) scanf("%d", &n[i].val);
        else {
            n[i].child.resize(tmp);
            for(int j = 0; j < tmp; j++) 
                scanf("%d", &n[i].child[j]);
        }
    }
    dfs(0, P);
    printf("%.1lf", ans);
    return 0;
}