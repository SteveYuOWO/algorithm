#include <iostream>
using namespace std;
const int N = 1000010;
int q[N], a[N], n;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int hh = 0, tt = -1;
    for(int i = 0; i < n; i++) {
        if(hh <= tt && q[hh] < i - k + 1) hh++;
        while(hh <= tt && a[q[hh]] >= a[i]) tt--;
        q[++tt] = i;
        if(i >= k - 1) printf("%d", a[q[hh]]);
    }
    return 0;
}