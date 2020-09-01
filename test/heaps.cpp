#include <iostream>
#include <vector>
using namespace std;
int M, N, v[1100], cnt;
void post(int u) {
    if(u >= N) return;
    post(2 * u + 1); post(2 * u + 2);
    cnt++;
    if(cnt != N) printf("%d ", v[u]);
    else printf("%d\n", v[u]);
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &M, &N);
    while(M--) {
        for(int i = 0; i < N; i++)
            scanf("%d", &v[i]);
        int type = v[0] > v[1]; // 1 max 0 min -1 not
        for(int i = 0; i < N; i++) {
            if(2 * i + 1 < N) {
                if(type == 1 && v[i] < v[2 * i + 1]) type = -1;
                if(type == 0 && v[i] > v[2 * i + 1]) type = -1;
            }
            if(2 * i + 2 < N) {
                if(type == 1 && v[i] < v[2 * i + 2]) type = -1;
                if(type == 0 && v[i] > v[2 * i + 2]) type = -1;
            }
        }
        if(type == 1) printf("Max Heap\n");
        else if(type == 0) printf("Min Heap\n");
        else printf("Not Heap\n");
        cnt = 0; post(0);
    }
    return 0;
}