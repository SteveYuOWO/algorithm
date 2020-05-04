#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N, arr[99999], a;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        arr[i] = i;
    for(int i = 1; i <= N; i++) {
        scanf("%d", &a);
        swap(arr[i], arr[a]);
    }
    printf("%d", arr[1]);
    for(int i = 2; i <= N; i++)
        printf(" %d", arr[i]);
    return 0;
}