#include <iostream>
#include <vector>
using namespace std;
int N, heap[99999], type;// -1 不是堆 1 最大堆 0 最小堆
void dfs(vector<int> path, int index) {
    path.push_back(heap[index]);
    if(2 * index + 1 >= N && 2 * index + 2 >= N) {
        printf("%d", path[0]);
        for(int i = 1; i < path.size(); i++)
            printf(" %d", path[i]);
        putchar('\n');
        return;
    } 
    if(2 * index + 2 < N) {
        if(type == 1 && heap[index] < heap[2 * index + 2]) type = -1;
        if(type == 0 && heap[index] > heap[2 * index + 2]) type = -1;
        dfs(path, 2 * index + 2);
    }
    if(2 * index + 1 < N) {
        if(type == 1 && heap[index] < heap[2 * index + 1]) type = -1;
        if(type == 0 && heap[index] > heap[2 * index + 1]) type = -1;
        dfs(path, 2 * index + 1);
    }
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", heap + i);
    type = heap[0] > heap[1];
    dfs({}, 0);
    if(type == 1) printf("Max Heap\n");
    else if(type == 0) printf("Min Heap\n");
    else printf("Not Heap\n");
    return 0;
}
