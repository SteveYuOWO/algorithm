#include <iostream>
#include <vector>
using namespace std;
int N, M, K, a, b;
vector<int> ans;
bool process(vector<int> dig, vector<vector<int>>& next) {
    int tmp, bef, ret = false;
    scanf("%d", &bef);
    for(int i = 1; i < N; i++) {
        scanf("%d", &tmp);
        if(dig[bef] != 0) ret = true;
        for(int j = 0; j < next[bef].size(); j++) 
            dig[next[bef][j]]--;
        bef = tmp;
    }
    return ret;
}
int main() {
    scanf("%d%d", &N, &M);
    vector<int> dig(N + 1);
    vector<vector<int>> next(N + 1);
    while(M--) {
        scanf("%d%d", &a, &b);
        dig[b]++;
        next[a].push_back(b);
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++) 
        if(process(dig, next)) ans.push_back(i);
    printf("%d", ans[0]);
    for(int i = 1; i < ans.size(); i++)
        printf(" %d", ans[i]);
    return 0;
}
