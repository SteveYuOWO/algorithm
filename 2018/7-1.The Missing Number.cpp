#include <iostream>
#include <map>
using namespace std;
map<int, int> m;
int main() {
    int N, tmp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if(tmp > 0) m[tmp] = 1;
    }
    int ans = 1;
    while(m[ans] != 0) ans++;
    printf("%d\n", ans);
    return 0;
}
