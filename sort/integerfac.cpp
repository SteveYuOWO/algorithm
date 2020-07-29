#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int N, K, P, maxFacSum = -1;
vector<int> v, ans, tmpAns;
void init() {
    int tmp = 0, index = 1;
    while(tmp <= N) {
        v.push_back(tmp);
        tmp = pow(index++, P);
    }
}
void dfs(int index, int tmpSum, int tmpK, int facSum) {
    if(tmpK == K) {
        if(tmpSum == N && facSum > maxFacSum) {
            ans = tmpAns;
            maxFacSum = facSum;
        }
        return;
    }
    while(index >= 1) {
        if(tmpSum + v[index] <= N) {
            tmpAns[tmpK] = index;
            dfs(index, tmpSum + v[index], tmpK + 1, facSum + index);
        } 
        if(index == 1) return;
        index--;
    }
}
int main() {
    scanf("%d%d%d", &N, &K, &P);
    init();
    tmpAns.resize(K);
    dfs(v.size() - 1, 0, 0, 0);
    if(maxFacSum == -1) printf("Impossible");
    else {
        printf("%d = ", N);
        for(int i = 0; i < ans.size(); i++) {
            if(i != 0) printf(" + ");
            printf("%d^%d", ans[i], P);
        }
    }
    return 0;
}