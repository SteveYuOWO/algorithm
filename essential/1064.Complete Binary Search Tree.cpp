#include <iostream>
#include <algorithm>
using namespace std;
int N, q[1010], ans[1010], q_i = 0;
void inorder(int index) {
    if(2 * index + 1 < N) inorder(2 * index + 1);
    ans[index] = q[q_i++];
    if(2 * index + 2 < N) inorder(2 * index + 2);
}
int main() {
    scanf("%d", &N);
    fill(ans, ans + 1010, -1);
    for(int i = 0; i < N; i++) scanf("%d", &q[i]);
    sort(q, q + N);
    inorder(0);
    printf("%d", ans[0]);
    for(int i = 1; i < N; i++) printf(" %d", ans[i]);
    putchar('\n');
    return 0;
}