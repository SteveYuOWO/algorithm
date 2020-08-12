#include <iostream>
using namespace std;
void quick_sort(int* q, int l, int r) {
    if(l >= r) return;
    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    while(i < j) {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j); quick_sort(q, j + 1, r);
}
int main() {
    int arr[] = {4, 3, 4, 5, 1, 0, -1, 2, 10};
    quick_sort(arr, 0, sizeof(arr) / sizeof(int));
    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf("%d ", arr[i]);
    return 0;
}