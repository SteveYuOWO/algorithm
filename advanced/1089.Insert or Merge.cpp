#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N), v2(N);
    for(int i = 0; i < N; i++) 
        scanf("%d", &v[i]);
    for(int i = 0; i < N; i++) 
        scanf("%d", &v2[i]);
    int i, j;
    for(i = 0; i < N; i++)
        if(v2[i] > v2[i + 1]) break;
    for(j = i+1; j < N; j++)
        if(v[j] != v2[j]) break;
    if(j == N) {
        printf("Insertion Sort\n");
        sort(v.begin(), v.begin() + i + 2);
    } else {
        printf("Merge Sort\n");
        int k = 1, flag = 1;
        while(flag) {
            flag = 0;
            for(i = 0; i < N; i++) 
                if(v[i] != v2[i]) flag = 1;
            k <<= 1;
            for(i = 0; i < N/k; i++)
                sort(v.begin() + i * k, v.begin() + (i + 1) * k);
            sort(v.begin() + i * k, v.end());
        }
    }
    printf("%d", v[0]);
    for(int i = 1; i < N; i++)
        printf(" %d", v[i]);
    return 0;
}