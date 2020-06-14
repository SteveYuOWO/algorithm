#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> m;
int main() {
    int num, out = 1;
    while(1) {
        scanf("%d", &num);
        if(num == -1) break;
        m[num]++;
    }
    while(1) {
        scanf("%d", &num);
        if(num == -1) break;
        if(m[num]) {
            m[num]--;
            if(out) {
                out = 0;
                printf("%d", num);
            } else printf(" %d", num);
        }
    }
    if(out == 1) printf("NULL");
    return 0;
}
