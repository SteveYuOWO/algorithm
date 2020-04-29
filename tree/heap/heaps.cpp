#include "iostream"
#include "vector"
using namespace std;
int M, N, heap;
vector<int> v, ans;
void post(int root, vector<int>& ans) {
    if(2 * root + 1 < N) post(2 * root + 1, ans);
    if(2 * root + 2 < N) post(2 * root + 2, ans);
    ans.push_back(v[root]);
}
int main() {
    scanf("%d%d", &M, &N);
    v.resize(N);
    while(M--) {
        bool start = true;
        for(int i = 0; i < N; i++)
            scanf("%d", &v[i]);
        if(v[0] > v[1]) heap = 1;
        else heap = -1;
        for(int i = (N - 1) / 2; i >= 0; i--) {
            if(heap == 1 && v[i] < v[2 * i + 1]) heap = 0;
            if(heap == -1 && v[i] > v[2 * i + 1]) heap = 0;
            if(2 * i + 2 < N) {
                if(heap == 1 && v[i] < v[2 * i + 2]) heap = 0;
                if(heap == -1 && v[i] > v[2 * i + 2]) heap = 0;
            }
        }
        ans.clear();
        post(0, ans);
        if(heap == 1) printf("Max Heap\n");
        else if(heap == 0) printf("Not Heap\n");
        else printf("Min Heap\n");
        printf("%d", ans[0]);
        for(int i = 1; i < N; i++) 
            printf(" %d", ans[i]);
        putchar('\n');
    }
    return 0;
}