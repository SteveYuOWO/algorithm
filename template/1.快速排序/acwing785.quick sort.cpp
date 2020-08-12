#include <iostream>
using namespace std;
void quick_sort(int *q, int l, int r) {
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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, arr[100100];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    quick_sort(arr, 0, n - 1);
    cout << arr[0];
    for(int i = 1; i < n; i++)
        cout << " " << arr[i];
}