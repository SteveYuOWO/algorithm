#include <iostream>
#include <map>
using namespace std;
map<int, int> m;
int main() {
    int num, flag = 1;
    while(1) {
        scanf("%d", &num);
        if(num == -1) break;
        m[num]++;
    }
    while(1) {
        scanf("%d", &num);
        if(num == -1) break;
        m[num]++;
    }
    for(auto& x: m) {
        while(x.second--) {
            if(flag) {
                flag = 0;
                printf("%d", x.first);
            } else printf(" %d", x.first);
        }
    }
    if(flag) printf("NULL");
    return 0;
}
