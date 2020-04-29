#include <iostream>
using namespace std;
int arr[] = { 4, 1, 1, 9, 1 };
int _prev[] = { 0, 0, 1, 2, 3, 4 };
int optimize[5];
int main() {
    optimize[0] = optimize[1] = max(arr[0], arr[1]);
    for(int i = 2; i < sizeof(arr); i++)
        optimize[i] = max(optimize[i - 1], arr[i] + optimize[i - 2]);
    printf("%d", optimize[4]);
    return 0;
}