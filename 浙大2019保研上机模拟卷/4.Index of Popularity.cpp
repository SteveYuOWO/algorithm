#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N, M, K, a, b;
vector<pair<int, int>> e;
unordered_map<int, int> degree;
bool cmp(int& m, int& n) {
    if(degree[m] != degree[n]) return degree[m] < degree[n];
    return m > n;
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d", &a, &b);
        e.push_back({a, b});
    }
    while(1) {
        scanf("%d", &K);
        if(K == 0) break;
        degree.clear();
        vector<int> v(K);
        unordered_map<int, int> exist;
        for(int i = 0; i < K; i++) {
            scanf("%d", &v[i]);
            exist[v[i]] = 1;
        }
        for(auto x: e) {
            if(exist[x.first] && exist[x.second]) {
                degree[x.first]++;
                degree[x.second]++;
            }
        }
        sort(v.begin(), v.end(), cmp);
        printf("%d %d %d\n", v[v.size()-1], v[v.size()-2], v[v.size()-3]);
    }
    return 0;
}
