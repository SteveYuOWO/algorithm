#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int n = 101000;
int N, q[n], q2[n], M = -1;
vector<int> ans;
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &q[i]), q2[i] = q[i];
    sort(q2, q2 + N);
    for(int i = 0; i < N; i++) {
        if(q[i] == q2[i] && q[i] > M)
            ans.push_back(q[i]);
        M = max(M, q[i]);
    }
    printf("%lu\n", ans.size());
    if(ans.size() != 0) printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);
    putchar('\n');
    return 0;
}