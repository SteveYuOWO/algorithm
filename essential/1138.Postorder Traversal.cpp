#include <iostream>
// 考察 前中建树
using namespace std;
const int n = 50500;
int N, pre[n], in[n];
void getPost(int root, int start, int end) {
    if(start > end) return ;
    int k = start;
    while(k < end && pre[root] != in[k]) k++;
    getPost(root + 1, start, k - 1);
    getPost(root + 1 + k - start, k + 1, end);
    printf("%d", in[k]);
    exit(0);
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &pre[i]);
    for(int i = 0; i < N; i++) scanf("%d", &in[i]);
    getPost(0, 0, N - 1);
    return 0;
}