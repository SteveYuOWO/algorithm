#include <iostream>
#include <vector>
#include <set>
using namespace std;
int N, M, path[300][300] = {0}, a, b, c, K, n;
int short_K = -1, short_V = 999999;
int main() {
    cin >> N >> M;
    while(M--) {
        cin >> a >> b >> c;
        path[a][b] = path[b][a] = c;
    }
    cin >> K;
    for(int c = 1; c <= K; c++) {
        int price = 0, NA = false;
        cin >> n;
        vector<int> v(n);
        set<int> s;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            s.insert(v[i]);
            if(i != 0) {
                if(path[v[i - 1]][v[i]] != 0) price += path[v[i - 1]][v[i]];
                else NA = true;
            }
        }
        if(NA) printf("Path %d: NA (Not a TS cycle)\n", c);
        else {
            if(s.size() == N && v[0] == v[n - 1]) {
                if(n - 1 == N) printf("Path %d: %d (TS simple cycle)\n", c, price);
                else printf("Path %d: %d (TS cycle)\n", c, price);
                if(price < short_V) {
                    short_V = price;
                    short_K = c;
                }
            } else printf("Path %d: %d (Not a TS cycle)\n", c, price);
        }
    }
    printf("Shortest Dist(%d) = %d\n", short_K, short_V);
    return 0;
}