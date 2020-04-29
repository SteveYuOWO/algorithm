#include "iostream"
#include "vector"
using namespace std;
int N, heap = -1;
vector<int> v, p;
void dfs(int root, vector<int> path) {
    path.push_back(v[root]);
    if(2 * root + 2 < N) {
        if(heap == 1 && v[root] < v[2 * root + 2]) heap = 0;
        if(heap == -1 && v[root] > v[2 * root + 2]) heap = 0;
        dfs(2 * root + 2, path);
    }
    if(2 * root + 1 < N) {
        if(heap == 1 && v[root] < v[2 * root + 1]) heap = 0;
        if(heap == -1 && v[root] > v[2 * root + 1]) heap = 0;
        dfs(2 * root + 1, path);
    }
    if(2 * root + 1 >= N && 2 * root + 2 >= N) {
        printf("%d", path[0]);
        for(int i = 1; i < path.size(); i++) 
            printf(" %d", path[i]);
        putchar('\n');
    }
}
int main() {
    scanf("%d", &N);
    v.resize(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i]);
    if(v[0] > v[1]) heap = 1;
    dfs(0, p);
    if(heap == 0) printf("Not Heap\n");
    else if(heap == 1) printf("Max Heap\n");
    else printf("Min Heap\n");
    return 0;
}