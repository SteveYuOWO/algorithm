#include <iostream>
using namespace std;
int M, N, tree[2000], judge, start;
void dfs(int index) {
    if(2 * index + 1 < N) {
        if(judge == 1 && tree[index] < tree[2 * index + 1]) judge = -1;
        if(judge == 0 && tree[index] > tree[2 * index + 1]) judge = -1;
        dfs(2 * index + 1);
    }
    if(2 * index + 2 < N) {
        if(judge == 1 && tree[index] < tree[2 * index + 2]) judge = -1;
        if(judge == 0 && tree[index] > tree[2 * index + 2]) judge = -1;
        dfs(2 * index + 2);
    }
}
void post(int index) {
    if(index >= N) return;
    post(2 * index + 1);
    post(2 * index + 2);
    if(start) {
        printf("%d", tree[index]);
        start = !start;
    } else printf(" %d", tree[index]);
}
int main() {
    cin >> M >> N;
    while(M--) {
        for(int i = 0; i < N; i++) cin >> tree[i];
        judge = tree[0] > tree[1]; // judge 1 大根 0 根 -1 不是
        dfs(0);
        if(judge == 1) cout << "Max Heap" << endl;
        else if(judge == 0) cout << "Min Heap" << endl;
        else cout << "Not Heap" << endl;
        start = 1;
        post(0);
        cout << endl;
    }
    return 0;
}