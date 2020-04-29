#include <stdio.h>
int fibnacci_recrusion(int n) {
    if(n == 1 || n == 2) return 1;
    return fibnacci_recrusion(n - 1) + fibnacci_recrusion(n - 2);
}
int fibnacci_loop(int n) {
    int arr[99999];
    arr[1] = arr[2] = 1;
    for(int i = 3; i <= n; i++) 
        arr[i] = arr[i - 1] + arr[i - 2];
    return arr[n];
}
int main() {
    printf("%d\n",fibnacci_recrusion(20));
    // printf("%d\n",fibnacci_loop(20));
    return 0;
}