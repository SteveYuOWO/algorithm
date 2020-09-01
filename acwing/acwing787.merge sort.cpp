#include <iostream>
using namespace std;
int tmp[100010];
void merge_sort(int q[], int l, int r) {
    if(l >= r) return;
    
    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r) 
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    for(i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}
int main(int argc, char const *argv[]) {
    int n, arr[100100];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    cout << arr[0];
    for(int i = 1; i < n; i++)
        cout << " " << arr[i];
    return 0;
}
