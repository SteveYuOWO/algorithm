#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct people {
    string id;
    int fr, ln, lr, score;
};
vector<vector<people>> v;
vector<people> res;
bool cmp(people& p1, people& p2){
    return p1.score == p2.score ? p1.id < p2.id: p1.score > p2.score;
}
int main(){
    int N, M;
    cin >> N;
    v.resize(N);
    people tmp;
    for(int i = 0; i < N; i++){
        cin >> M;
        tmp.ln = i + 1;
        while(M--) {
            cin >> tmp.id >> tmp.score;
            v[i].push_back(tmp);
        }
        sort(v[i].begin(), v[i].end(), cmp);
        if(v[i].size() != 0){
            v[i][0].lr = 1;
            for(int j = 2; j <= v[i].size(); j++)
                if(v[i][j-1].score != v[i][j-2].score) v[i][j-1].lr = j;
                else v[i][j-1].lr = v[i][j-2].lr;
        }
    }
    for(int i = 0;i < v.size(); i++)
        for(int j = 0;j < v[i].size(); j++)
            res.push_back(v[i][j]);
    sort(res.begin(), res.end(), cmp);
    res[0].fr = 1;
    for(int i = 2;i <= res.size(); i++)
        if(res[i-1].score != res[i-2].score) res[i-1].fr = i;
        else res[i-1].fr = res[i-2].fr;
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++)
        cout << res[i].id << " " << res[i].fr << " "
            << res[i].ln << " " << res[i].lr << endl;
    return 0;
}
