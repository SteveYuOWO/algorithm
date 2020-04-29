#include "iostream"
#include "vector"
#include "stack"
using namespace std;
int heap[999999], heap_size = 0;
void insert(int data) {
    int i;
    for(i = ++heap_size; data < heap[i / 2]; i /= 2)
        heap[i] = heap[i / 2];
    heap[i] = data;
}
int main() {
    int N, M, tmp;
    heap[0] = -99999;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &tmp);
        insert(tmp);
    }
    while(M--) {
        scanf("%d", &tmp);
        for(int i = tmp; i > 0; i /= 2)
            if(i == tmp) printf("%d", heap[i]);
            else printf(" %d", heap[i]);
        printf("\n");
    }
    return 0;
}
