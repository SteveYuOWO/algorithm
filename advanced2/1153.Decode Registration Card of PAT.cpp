#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N, M, choose;
string tmp;
pair<string, int> cards[11000];
bool cmp(pair<string, int> p1, pair<string, int> p2) {
    return p1.second != p2.second ? p1.second > p2.second : p1.first < p2.first;
}
int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)  
        cin >> cards[i].first >> cards[i].second;
    for(int c = 1; c <= M; c++) {
        cin >> choose >> tmp;
        printf("Case %d: %d %s\n", c, choose, tmp.c_str());
        if(choose == 1) {
            vector<pair<string, int>> v;
            for(int i = 0; i < N; i++) 
                if(cards[i].first[0] == tmp[0]) v.push_back(cards[i]);
            if(v.size() != 0) {
                sort(v.begin(), v.end(), cmp);
                for(auto x : v) printf("%s %d\n", x.first.c_str(), x.second);
            } else printf("NA\n");
        } else if(choose == 2) {
            int cnt = 0, all_score = 0;
            for(int i = 0; i < N; i++) {
                if(cards[i].first.substr(1, 3) == tmp) {
                    cnt++; 
                    all_score += cards[i].second;
                }
            }
            if(cnt != 0) printf("%d %d\n", cnt, all_score);
            else printf("NA\n");
        }else {
            unordered_map<string, int> m;
            for(int i = 0; i < N; i++) 
                if(cards[i].first.substr(4, 6) == tmp) 
                    m[cards[i].first.substr(1, 3)]++;
            if(m.size() != 0) {
                vector<pair<string, int>> v(m.begin(), m.end());
                sort(v.begin(), v.end(), cmp);
                for(auto x: v) printf("%s %d\n", x.first.c_str(), x.second);
            } else printf("NA\n");
        }
    }
    return 0;
}
// B 123 180908 127
// 1 decreasing
// 2 Nt Ns
// 3 Nnumber testee