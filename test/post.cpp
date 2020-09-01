#include <iostream>
using namespace std;
int N, pre[50500], in[50500];
void getPost(int u, int l, int r) {
    if(l > r) return;
    int i = l;
    while(i < r && pre[u] != in[i]) i++;
    getPost(u + 1, l, i - 1);
    getPost(u + 1 + i - l, i + 1, r);
    printf("%d\n", pre[u]);
    exit(0);
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &pre[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    getPost(0, 0, N - 1);
    return 0;
}