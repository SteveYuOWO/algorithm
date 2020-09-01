#include <iostream>
using namespace std;
// 快速选择
// 选择次数 Sn = n + 1/2 n + 1/4 n + 1/8 n ... 
// 所以 Sn = 2n 排序复杂度为 O(n)
int quick_select(int *q, int l, int r, int k) {
    if (l == r) return q[l];

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j) {
        do i++ ; while (q[i] < x);
        do j-- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    
    if (k <= j - l + 1) return quick_select(q, l, j, k);
    return quick_select(q, j + 1, r, k - (j - l + 1));
}
int main() { 
    int n, k, q[100100];
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    printf("%d\n", quick_select(q, 0, n - 1, k));
    return 0;
}