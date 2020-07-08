#include <iostream>
#include <vector>
int N, arr[1100];
int isHeap;
using namespace std;
void dfs(int root, vector<int> path) {
    path.push_back(arr[root]);
    if(2 * root + 2 < N) {
        if(isHeap == 1 && arr[root] < arr[2 * root + 2]) isHeap = -1; 
        if(isHeap == 0 && arr[root] > arr[2 * root + 2]) isHeap = -1; 
        dfs(2 * root + 2, path);
    }
    if(2 * root + 1 < N) {
        if(isHeap == 1 && arr[root] < arr[2 * root + 1]) isHeap = -1; 
        if(isHeap == 0 && arr[root] > arr[2 * root + 1]) isHeap = -1; 
        dfs(2 * root + 1, path);
    }
    if(2 * root + 1 >= N && 2 * root + 2 >= N) {
        if(path.size() != 0) printf("%d", path[0]);
        for(int i = 1; i < path.size(); i++)
            printf(" %d", path[i]);
        putchar('\n');
    }
}
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    isHeap = arr[0] > arr[1]; 
    vector<int> path;
    dfs(0, path);
    // 0节点是否比1节点大， 大跟堆 1， 小跟堆 0， 不是堆 -1
    if(isHeap == 1) printf("Max Heap\n");
    else if(isHeap == 0) printf("Min Heap\n");
    else printf("Not Heap\n");
    return 0;
}
