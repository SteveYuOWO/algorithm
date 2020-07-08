#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, M, a, b, sum = 0;
    scanf("%d", &N);
    vector<int> dis(N + 1);
    dis[0] = 0;
    for(int i = 1; i <= N; i++) {
        scanf("%d", &dis[i]);
        sum += dis[i];
        dis[i] += dis[i - 1];
    }
    scanf("%d", &M);
    while(M--) {
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        int len = dis[b - 1] - dis[a - 1];
        printf("%d\n", min(sum - len, len));
    }
    system("pause");
    return 0;
}
