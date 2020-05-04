#include <iostream>
#include <cmath>
#include <map>
using namespace std;
int main() {
    int N, tmp;
    scanf("%d", &N);
    while(N--) {
        int ans = 0, cnt = 0;
        scanf("%d", &tmp);
        map<int, bool> m;
        if(tmp == 1) {
            printf("0\n");
            continue;
        }
        m[tmp] = 1;
        while(true) {
            cnt++;
            while(tmp != 0) {
                ans += pow(tmp % 10, 3);
                tmp /= 10;
            }
            if(m[ans] == 1 || ans == 1) {
                if(ans == 1) printf("%d\n", cnt);
                else printf("%d\n", ans);
                break;
            }
            m[ans] = 1;
            tmp = ans;
            ans = 0;
        }
    }
    return 0;
}