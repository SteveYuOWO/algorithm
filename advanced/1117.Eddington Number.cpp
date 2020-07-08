#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, e = 0;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; i++) 
        scanf("%d", &v[i]);
    sort(v.begin(), v.end(), greater<int>());
    while(e < N && v[e] > e+1) e++;
    printf("%d", e);
    return 0;
}