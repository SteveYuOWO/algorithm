#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int N, K, set_index = 0;
map<string, int> m;
set<string> s[9999];
int all_score[9999] = {0};
int score;
int main() {
    string name1, name2;
    cin >> N >> K;
    while(N--) {
        cin >> name1 >> name2 >> score;
        if(m[name1] != 0 || m[name2] != 0) {
            for(int i = 0; i < set_index; i++) 
                if(s[i].find(name1) != s[i].end() || s[i].find(name2) != s[i].end()) {
                    s[i].insert(name1);
                    s[i].insert(name2);
                    all_score[i] += score;
                }
        } else {
            s[set_index].insert(name1);
            s[set_index].insert(name2);
            all_score[set_index++] += score;
        }
        m[name1] += score;
        m[name2] += score;
    }
    int ans_sz = 0;
    vector<pair<string, int>> ans;
    for(int i = 0; i < set_index; i++) {
        string k; 
        int v = -1, cnt;
        set<string>* group = &s[i];
        for(auto x: s[i]) {
            if(m[x] > v) {
                k = x;
                v = m[x];
                group = &s[i];
                cnt = 1;
            } else if(m[x] == v) cnt++;
        } 
        if(cnt == 1 && all_score[i] > K) {
            ans_sz++;
            ans.push_back({k, group->size()});
        }
    }
    cout << ans_sz << endl;
    for(int i = 0; i < ans_sz; i++) 
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}