#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[11000];
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + N);
    double ans = arr[0];
    for(int i = 1; i < N; i++)
        ans = ((ans + arr[i]) / 2);
    printf("%d", (int)ans);
    return 0;
}