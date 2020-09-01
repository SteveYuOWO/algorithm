#include <iostream>
using namespace std;
int a[5] = {-1, 2, 10, -2, 0}, n = 5;
void quick_sort(int *q, int l, int r) {
    if(l >= r) return;
    swap(q[l + r >> 1], q[l]);
    int i = l - 1, j = r + 1, x = q[l + r >> 1]; // 这边q[l] q[r]都行，这是pivot
    while(i < j) {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    cout << j << endl;
    // quick_sort(q, l, j); quick_sort(q, j + 1, r);
}
int main() {
    quick_sort(a, 0, 4);
    for(int i = 0; i < 5; i++)
        cout << a[i] << " ";
    return 0;
}