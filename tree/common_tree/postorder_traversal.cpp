#include "iostream"
using namespace std;
int N, k = 0;
int pre[50500], in[50500], post[50500];
void get_post(int root, int start, int end) {
    if(start > end) return;
    int i = start;
    while(i < end && pre[root] != in[i]) i++;
    get_post(root + 1, start, i - 1);
    get_post(root + 1 + (i - start), i + 1, end);
    post[k++] = in[i];
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) 
        scanf("%d", pre + i);
    for(int i = 0; i < N; i++)
        scanf("%d", in + i);
    get_post(0, 0, N - 1);
    printf("%d", post[0]);
    return 0;
}
