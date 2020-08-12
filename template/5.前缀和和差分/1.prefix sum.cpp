#include <iostream>
using namespace std;
int main() {
    int arr[100010];
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i++)
        arr[i] += arr[i-1];
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", arr[b] - arr[a-1]);
    }
    return 0;
}
