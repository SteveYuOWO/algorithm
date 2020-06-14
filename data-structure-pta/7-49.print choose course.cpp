#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
unordered_map<string, set<int>> m;
int main() {
    int N, K, a, b;
    char ch[10];
    scanf("%d%d", &N, &K);
    while(K--) {
        scanf("%d%d", &a, &b);
        while(b--) {
            scanf("%s", ch);
            m[ch].insert(a);
        }
    }
    while(N--) {
        scanf("%s", ch);
        printf("%s %lu", ch, m[ch].size());
        for(auto& x: m[ch]) 
            printf(" %d", x);
        putchar('\n');
    }
    return 0;
}
