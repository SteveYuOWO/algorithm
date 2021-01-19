#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct node {
    int k, v;
    bool operator<(const node& n) const {
        if(v != n.v) return v > n.v;
        return k < n.k;
    }
};
bool exits[99999];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int N, K, tmp;
    scanf("%d%d", &N, &K);
    set<node> s;
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if(i > 0) {
            int copyK = K;
            printf("%d:", tmp);
            for(auto& x: s) {
                if(copyK == 0) break;
                copyK--;
                printf(" %d", x.k);
            }
            printf("\n");
        }
        if(exits[tmp]) {
            auto it = s.begin();
            while(it->k != tmp) it++;
            int newv = it->v + 1;
            s.erase(it);
            s.insert({tmp, newv});
        } else s.insert({tmp, 1});
        exits[tmp] = 1;
    }
    return 0;
}
