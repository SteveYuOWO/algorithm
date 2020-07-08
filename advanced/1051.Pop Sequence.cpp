#include "iostream"
#include "stack"
#include "vector"
using namespace std;
int main() {
    int M, N, K, tmp, cur;
    scanf("%d%d%d", &M, &N, &K);
    for(int i = 0; i < K; i++) {
        stack<int> sta;
        vector<int> v(N);
        cur = 0;
        for(int j = 0; j < N; j++) 
            scanf("%d", &v[j]);
        for(int j = 1; j <= N; j++) {
            sta.push(j);
            if(sta.size() > M) break;
            while(!sta.empty() && sta.top() == v[cur]) {
                cur++;
                sta.pop();
            }
        }
        if(cur != N) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}