#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N, M, a[999999], b[999999], ans = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", a + i);
    scanf("%d", &M);
    for(int i = 0; i < M; i++) scanf("%d", b + i);
    sort(a, a + N); sort(b, b + M);
    for(int i = 0; i < min(N, M); i++)
        if(a[i] < 0 && b[i] < 0) ans += a[i] * b[i];
    for(int i = N - 1, j = M - 1; i >= 0 && j >= 0; i--, j--)
        if(a[i] > 0 && b[j] > 0) ans += a[i] * b[j];
    printf("%d", ans);
    return 0;
}
