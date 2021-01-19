#include <iostream>
#include <vector>
using namespace std;
struct node {
    vector<int> child;
};
int N, tmp, K; double P, r;
int minnLevel = 99999999, cnt = 0; double price;
vector<node> v;
void dfs(int root, int level, double tmpPrice) {
    if(v[root].child.size() == 0) {
        if(level < minnLevel) {
            minnLevel = level;
            cnt = 1;
            price = tmpPrice;
        } else if(level == minnLevel) cnt++;
        return;
    }
    for(int i = 0; i < v[root].child.size(); i++) 
        dfs(v[root].child[i], level + 1, tmpPrice * (1.0 + r/100.0));
}
int main() {
    scanf("%d%lf%lf", &N, &P, &r);
    v.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &K);
        while(K--) {
            scanf("%d", &tmp);
            v[i].child.push_back(tmp);
        }
    }
    dfs(0, 0, P);
    printf("%.4f %d", price, cnt);
    return 0;
}