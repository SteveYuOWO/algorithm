#include <stdio.h>
int main() {
    char arr[3];
    gets(arr);
    puts(arr);
    printf("%d", sizeof(arr));
    return 0;
}