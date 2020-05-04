#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
int N, M, K;
char a[10], b[10];
unordered_map<string, unordered_set<string>> frien;
unordered_map<string, unordered_set<string>> homo;
int main() {
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%s%s", a, b);
        frien[a].insert(b);
        frien[b].insert(a);
        if(strlen(a) == strlen(b)) {
            homo[a].insert(b);
            homo[b].insert(a);
        }
    }
    scanf("%d", &K);
    while(K--) {
        scanf("%s%s", a, b);
        vector<pair<string, string>> v;
        for(auto x: homo[a]) 
            for(auto y: homo[b]) 
                if(x != b && y != a && frien[x].find(y) != frien[x].end()) 
                    v.push_back({x, y});
        sort(v.begin(), v.end());
        printf("%lu\n", v.size());
        for(auto x: v) {
            if(x.first.length() == 5) x.first = x.first.substr(1);
            if(x.second.length() == 5) x.second = x.second.substr(1);
            printf("%s %s\n", x.first.c_str(), x.second.c_str());
        }
    }
    return 0;
}