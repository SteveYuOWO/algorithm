#include <iostream>
using namespace std;
int pre[99999], in[99999], post[99999], c = 0, N;
void postorder(int root, int start, int end) {
    if(start > end) return;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    postorder(root + 1, start, i - 1);
    postorder(root + 1, i + 1, end);
    post[c++] = in[i];
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &pre[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    postorder(0, 0, N - 1);
    printf("%d", post[0]);
    return 0;
}