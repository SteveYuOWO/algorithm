#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct Card {
    string cardnum;
    int score;
    Card() { cardnum.resize(20); }
    bool operator<(const Card& c) const {
        if(score != c.score) return score > c.score;
        return cardnum < c.cardnum;
    }
}c[99999];
int N, M, op;
char instruct[20];
bool cmp(pair<string, int>& p1, pair<string, int>& p2) {
    if(p1.second != p2.second) return p1.second > p2.second;
    return p1.first < p2.first;
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) 
        scanf("%s%d", &c[i].cardnum[0], &c[i].score);
    for(int i = 0; i < M; i++) {
        scanf("%d%s", &op, instruct);
        printf("Case %d: %d %s\n", i + 1, op, instruct);
        if(op == 1) {
            vector<Card> v;
            for(int i = 0; i < N; i++) 
                if(c[i].cardnum[0] == instruct[0]) v.push_back(c[i]);
            if(v.size() != 0) {
                sort(v.begin(), v.end());
                for(auto& x: v)
                    printf("%s %d\n", x.cardnum.c_str(), x.score);
            } else printf("NA\n");
        } else if(op == 2) {
            int cnt = 0, score = 0;
            for(int i = 0; i < N; i++) {
                if(c[i].cardnum.substr(1, 3) == instruct) {
                    cnt++;
                    score += c[i].score;
                }
            }
            if(cnt != 0) printf("%d %d\n", cnt, score);
            else printf("NA\n");
        } else if(op == 3) {
            unordered_map<string, int> m;
            for(int i = 0; i < N; i++) {
                if(c[i].cardnum.substr(4, 6) == instruct) {
                    m[c[i].cardnum.substr(1, 3)]++;
                }
            }
            if(m.size()) {
                vector<pair<string, int>> v(m.begin(), m.end());
                sort(v.begin(), v.end(), cmp);
                for(auto& x: v) {
                    printf("%s %d\n", x.first.c_str(), x.second);
                }
            }else printf("NA\n");
        }
    }
    return 0;
}
