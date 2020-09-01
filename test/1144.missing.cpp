#include <iostream>
#include <map>
using namespace std;
map<int, bool> m;
int main() {
    int N, tmp, ans = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &tmp), m[tmp] = 1;
    while(m[ans]) ans++;
    printf("%d", ans);
    return 0;
}