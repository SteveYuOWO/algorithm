#include <iostream>
#include <vector>
using namespace std;
int N, q[1010], heapType; // 1 0 -1
void dfs(int u, vector<int> v) {
    if(u >= N) return;
    v.push_back(q[u]);
    if(2 * u + 1 >= N && 2 * u + 2 >= N) {
        printf("%d", v[0]);
        for(int i = 1; i < v.size(); i++)
            printf(" %d", v[i]);
        putchar('\n');
    }
    if(heapType == 1) {
        if(2 * u + 1 < N && q[u] < q[2 * u + 1]) heapType = -1;
        if(2 * u + 2 < N && q[u] < q[2 * u + 2]) heapType = -1;
    } else if(heapType == 0) {
        if(2 * u + 1 < N && q[u] > q[2 * u + 1]) heapType = -1;
        if(2 * u + 2 < N && q[u] > q[2 * u + 2]) heapType = -1;
    }
    dfs(2 * u + 2, v);
    dfs(2 * u + 1, v);
} 
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &q[i]);
    heapType = q[0] > q[1];
    dfs(0, {});
    if(heapType == 1) printf("Max Heap\n");
    else if(heapType == -1) printf("Not Heap\n");
    else printf("Min Heap\n");
    return 0;
}