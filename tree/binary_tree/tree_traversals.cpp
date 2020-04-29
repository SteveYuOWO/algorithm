#include "iostream"
using namespace std;
int N, print_i = 0;
int pre[10000] = {0},in[10000], post[10000];
void get_pre(int root, int start, int end, int index) {
    if(start > end) return;
    int i = start;
    while(i < end && post[root] != in[i]) i++;
    pre[index] = in[i];
    get_pre(root - 1 - (end - i), start, i - 1, 2 * index + 1);
    get_pre(root - 1, i + 1, end, 2 * index + 2);
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", post + i);
    for(int i = 0; i < N; i++)
        scanf("%d", in + i);
    get_pre(N - 1, 0, N-1, 0);
    printf("%d", pre[print_i++]);
    for(int i = 1; i < 10000; i++) 
        if(pre[i] && print_i++)  
            printf(" %d", pre[i]);
    return 0;
}