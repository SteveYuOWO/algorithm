#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
struct node {
    int k, v;
    bool operator < (const node& n) const {
        return v != n.v ? v > n.v : k < n.k;
    }
};
int N, K, tmp;
set<node> s;
unordered_map<int, int> m;
int main() {
    scanf("%d%d", &N, &K);
    scanf("%d", &tmp);
    m[tmp]++; s.insert({tmp, m[tmp]});
    for(int i = 1; i < N; i++) {
        scanf("%d", &tmp);
        printf("%d:", tmp);
        auto it = s.begin();
        for(int i = 0; i < K && it != s.end(); i++, it++)
            printf(" %d", it->k);
        putchar('\n');
        it = s.find({tmp, m[tmp]});
        if(it != s.end()) s.erase(it);
        m[tmp]++;
        s.insert({tmp, m[tmp]});
    }
    return 0;
}