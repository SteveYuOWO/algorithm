#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int N, K, Q, a, b, fa, tmp, bird[10100];
unordered_map<int, int> m;
unordered_set<int> s, s_fa;
int findFather(int num) {
    int f = num;
    while(f != bird[f]) f = bird[f];
    while(num != f) {
        int x = bird[num];
        bird[num] = f;
        num = x;
    }
    return f;
}
void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb) bird[fb] = fa;
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < 10100; i++)
        bird[i] = i;
    while(N--) {
        scanf("%d%d", &K, &fa);
        s.insert(fa);
        for(int i = 1; i < K; i++) {
            scanf("%d", &tmp);
            Union(fa, tmp);
            s.insert(tmp);
        }
    }
    for(auto x: s) s_fa.insert(findFather(x));
    printf("%lu %lu\n", s_fa.size(), s.size());
    scanf("%d", &Q);
    while(Q--) {
        scanf("%d%d", &a, &b);
        int fa = findFather(a);
        int fb = findFather(b);
        printf("%s\n", fa == fb ? "Yes": "No");
    }
    return 0;
}