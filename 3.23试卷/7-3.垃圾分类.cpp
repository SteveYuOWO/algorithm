#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> m;
int main() {
    string tmp;
    tmp.resize(10);
    int val, N;
    scanf("%d", &N);
    while(N--) {
        fill(tmp.begin(), tmp.end(), 0);
        scanf("%s%d", &tmp[0], &val);
        m[tmp] = val;
    }
    while(true) {
        scanf("%s", &tmp[0]);
        if(tmp[0] == '#') break;
        switch (m[tmp]) {
            case 1: printf("Gan laji\n"); break;
            case 2: printf("Shi laji\n"); break;
            case 3: printf("Ke Hui Shou\n"); break;
            case 4: printf("You Hai laji\n"); break;
            default: printf("?\n"); break;
        }
    }
    return 0;
}