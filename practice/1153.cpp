#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N, M, op; string ops;
struct Card {
    string id; int score;
}c[10010];
bool cmp(Card& c1, Card& c2) {
    if(c1.score != c2.score) return c1.score > c2.score;
    return c1.id < c2.id;
}
bool cmp2(pair<string, int>& p1, pair<string, int>& p2) {
    if(p1.second != p2.second) return p1.second > p2.second;
    return p1.first < p2.first;
}
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> c[i].id >> c[i].score;
    for(int i = 1; i <= M; i++) {
        cin >> op >> ops;
        printf("Case %d: %d %s\n", i, op, ops.c_str());
        if(op == 1) {
            vector<Card> tmp;
            for(int i = 0; i < N; i++) 
                if(c[i].id[0] == ops[0]) tmp.push_back(c[i]);
            sort(tmp.begin(), tmp.end(), cmp);
            if(tmp.size()) for(auto& x: tmp) printf("%s %d\n", x.id.c_str(), x.score);
            else printf("NA\n");
        } else if(op == 2) {
            int cnt = 0, sum = 0;
            for(int i = 0; i < N; i++) 
                if(c[i].id.substr(1, 3) == ops) cnt++, sum += c[i].score;
            if(cnt != 0) printf("%d %d\n", cnt, sum);
            else printf("NA\n");
        } else if(op == 3) {
            unordered_map<string, int> m;
            for(int i = 0; i < N; i++) 
                if(c[i].id.substr(4, 6) == ops) m[c[i].id.substr(1, 3)]++;
            vector<pair<string, int>> v(m.begin(), m.end());
            sort(v.begin(), v.end(), cmp2);
            if(v.size()) for(auto& x: v) printf("%s %d\n", x.first.c_str(), x.second);
            else printf("NA\n");
        }
    }
}