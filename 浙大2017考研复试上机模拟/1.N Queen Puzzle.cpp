#include <iostream>
#include <cmath>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int K, N, arr[10000], x1, y1, x2, y2;
    scanf("%d", &K);
    while(K--) {
        scanf("%d", &N);
        string ans = "YES\n";
        for(int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
            x1 = i; y1 = arr[i];
            for(int j = 1; j < i; j++) {
                x2 = j; y2 = arr[j];
                if(x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) 
                    ans = "NO\n";
            }
        }
        printf("%s", ans.c_str());
    }
    return 0;
}
