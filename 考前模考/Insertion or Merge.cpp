#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999999999
using namespace std;
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N, arr1[200], arr2[200];
    fill(arr1, arr1 + 200, INF);
    fill(arr2, arr2 + 200, INF);
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr1[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &arr2[i]);
    int i = 0;
    while(arr2[i] < arr2[i + 1]) i++;
    int j = i + 1;
    while(j < N && arr2[j] == arr1[j]) j++;
    if(j == N) {
        cout << "Insertion Sort" << endl;
        sort(arr1, arr1 + i + 2);
    } else {
        cout << "Merge Sort" << endl;
        int merge = 1, cnt;
        while(true) {
            int k = 0;
            while(k < N && arr1[k] == arr2[k]) k++;
            if(k == N) break;
            merge <<= 1;
            cnt = N / merge;
            for(int i = 0; i < cnt; i++) 
                sort(arr1 + i * merge, arr1 + (i + 1) * merge);
        }
        merge <<= 1;
        for(int i = 0; i < cnt; i++) 
            sort(arr1 + i * merge, arr1 + (i + 1) * merge);
    }
    cout << arr1[0];
    for(int i = 1; i < N; i++)
        cout << " " << arr1[i];
    return 0;
}