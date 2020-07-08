#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int N, M, K, tmp, A, B;
    scanf("%d", &N);
    vector<set<int>> v(N + 1);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &M);
        while(M--){
            scanf("%d", &tmp);
            v[i].insert(tmp);
        }
    }
    scanf("%d", &K);
    while(K--) {
        int coun = 0;
        scanf("%d%d", &A, &B);
        for(auto it = v[A].begin(); it != v[A].end(); it++)
            if(v[B].find(*it) != v[B].end()) coun++;
        double ans = (coun * 100.0)/(v[A].size() + v[B].size() - coun);
        printf("%.1f%%\n", ans);
    }
    system("pause");
    return 0;
}
