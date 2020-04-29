#include "iostream"
#include "vector"
using namespace std;
int N, tmp, cnt;
double P, R, mv = 999999999;
struct node {
    double price;
    vector<int> child;
}n[999999];
void dfs(int root, double price) {
    n[root].price = price;
    if(n[root].child.size() == 0) {
        if(n[root].price < mv) {
            mv = n[root].price;
            cnt = 1;
        } else if(n[root].price == mv) cnt++;
    }
    for(int i = 0; i < n[root].child.size(); i++)
        dfs(n[root].child[i], price * (1.0 + R / 100.0));
}
int main() {
    scanf("%d%lf%lf", &N, &P, &R);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        n[i].child.resize(tmp);
        for(int j = 0; j < tmp; j++) 
            scanf("%d", &n[i].child[j]);
    }
    dfs(0, P);
    printf("%.4lf %d", mv, cnt);
    return 0;
}
