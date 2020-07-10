#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    char arr[15][2];
    printf("%p\n", arr);
    for(int i = 0; i < 15; i++)
        printf("%p\n", arr[0] + i);
    return 0;
}