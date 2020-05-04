#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int N, M, K;
string a, b;
unordered_map<string, vector<string>> m;
int main() {
    cin >> N >> M;
    while(N--) {
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    while(M--) {
        scanf("%d", &K);
        unordered_set<string> s;
        for(int i = 0; i < K; i++) {
            cin >> a;
            s.insert(a);
        }
        bool danger = false;
        for(auto x: s) {
            for(auto y: m[x]) {
                if(s.find(y) != s.end()) {
                    danger = true;
                    break;
                }
            }
            if(danger) break;
        }
        if(danger) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}