#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int K, N, tmp;
    scanf("%d", &K);
    while(K--) {
        scanf("%d", &N);
        vector<pair<int, int>> v;
        bool no = false;
        for(int c = 0; c < N; c++) {
            scanf("%d", &tmp);
            for(auto x: v) {
                if(x.first == c || x.second == tmp || ((x.first - c) == (x.second - tmp) && (x.first - c) * (x.second - tmp) > 0))
                    no = true;
            }
            v.push_back({c, tmp});
        }
        printf("%s\n", no ? "NO" : "YES");
    }
    return 0;
}