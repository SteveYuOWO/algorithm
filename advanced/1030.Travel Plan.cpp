#include <iostream>
using namespace std;
int arr[1000000] = {0}, arr2[1000000] = {0}, arr3[1000000] = {0};
int main() {
    int M, N;
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
        scanf("%d", arr+i);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", arr2+i);
    int i = 0, j = 0, k = 0;
    while(i < M && j < N) {
        if(arr[i] < arr2[j]) arr3[k++] = arr[i++];
        else arr3[k++] = arr2[j++];
        if(k == (M + N + 1) / 2)
             printf("%d\n", arr3[k - 1]);
    }
    while(i < M) {
        arr3[k++] = arr[i++];
        if(k == (M + N + 1) / 2)
             printf("%d\n", arr3[k - 1]);
    }
    while(j < N) {
        arr3[k++] = arr2[j++];
        if(k == (M + N + 1) / 2)
             printf("%d\n", arr3[k - 1]);
    }
    return 0;
}
