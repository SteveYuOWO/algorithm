#include <iostream>
#include <cmath>
#define CAPACITY 99999
using namespace std;
void counting_sort(int arr[], int size) {
    int count[CAPACITY] = {0}, rank[CAPACITY] = {0};
    for(int i = 0; i < size; i++) 
        count[arr[i]]++;
    for(int i = 1; i < CAPACITY; i++)
        count[i] += count[i - 1];
    for(int i = size - 1; i >= 0; i--)
        rank[--count[arr[i]]] = arr[i];
    for(int i = 0; i < size; i++)
        arr[i] = rank[i];
}
void radix_sort(int arr[], int L, int R, int digit) {
    int i, j = 0, help[R - L + 1];
    for(int d = 1; d <= digit; d++) {
        int count[10] = {0};
        for(i = L; i <= R; i++) {
            j = (arr[i] / (int)pow(10, d - 1)) % 10; // 取到第N位置
            count[j]++;
        }
        for(i = 1; i < 10; i++) 
            count[i] += count[i - 1];
        for(i = R; i >= L; i--) {
            j = (arr[i] / (int)pow(10, d - 1)) % 10; 
            help[--count[j]] = arr[i];
        }
        for(int i = L, j = 0; i <= R; i++, j++) 
            arr[i] = help[j];
    }
}
int main() {
    int arr[] = { 224, 343, 154, 454, 265, 176, 876, 987, 287, 11 };
    counting_sort(arr, sizeof(arr) / sizeof(int));
    printf("计数排序:");
    for(int i = 0; i < sizeof(arr) / sizeof(int); i++)
        printf(" %d", arr[i]);
    putchar('\n');
    int arr2[] = { 224, 343, 154, 454, 265, 176, 876, 987, 287, 11 };
    radix_sort(arr2, 0, sizeof(arr2) / sizeof(int) - 1, 3);
    printf("基数排序:");
    for(int i = 0; i < sizeof(arr2) / sizeof(int); i++)
        printf(" %d", arr2[i]);
    return 0;
}