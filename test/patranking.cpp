#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
string id, school; double sco;
unordered_map<string, double> cnt, score;
int N;
struct Rank {
    string school;
    int TWS;
    int cnt;
    bool operator<(const Rank& r) const {
        if(TWS != r.TWS) return TWS > r.TWS;
        if(cnt != r.cnt) return cnt < r.cnt;
        return school < r.school;
    }
};
set<Rank> s;
int main() {
    // freopen("in.txt", "r", stdin);
    cin >> N;
    while(N--) {
        cin >> id >> sco >> school;
        for(int i = 0; i < school.size(); i++) school[i] = tolower(school[i]);
        if(id[0] == 'T') sco *= 1.5;
        else if(id[0] == 'B') sco /= 1.5;
        cnt[school] += 1; score[school] += sco;
    }
    for(auto& x: score) s.insert({x.first, (int)x.second, (int)cnt[x.first]});
    cout << s.size() << endl;
    auto bef = s.begin(), next = ++s.begin(); int r = 1;
    cout << r << " " << bef->school << " " << bef->TWS << " " << bef->cnt << endl;
    for(int i = 2; i <= s.size(); i++, bef = next, next++) {
        if(next->TWS != bef->TWS) r = i;
        cout << r << " " << next->school << " " << next->TWS << " " << next->cnt << endl;
    }
    return 0;
}