#include <iostream>
#include <map>
using namespace std;
int main() {
    int N, M, tmp;
    map<int, int> m;
    scanf("%d%d", &N, &M);
    while(N--) {
        scanf("%d", &tmp);
        m[tmp]++;
    }
    for(auto it = m.begin(); it != m.end(); it++) {
        it->second--;
        if(m[M - it->first]) {
            printf("%d %d", it->first, M - it->first);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
