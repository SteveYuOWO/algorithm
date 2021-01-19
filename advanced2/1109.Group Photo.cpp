#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
bool cmp(pair<string, int>& p1, pair<string, int>& p2) {
    if(p1.second != p2.second) return p1.second > p2.second;
    return p1.first < p2.first;
}
int main() {
    cin >> N >> K;
    int col = N / K;
    vector<pair<string, int>> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    vector<deque<pair<string, int>>> tmp(K), ans(K);
    int i;
    for(i = 0; i < N - K * col; i++) 
        tmp[0].push_back(v[i]);
    for(int j = 0; j < K; j++) 
        for(int k = 0; k < col; k++, i++)
            tmp[j].push_back(v[i]);
    for(int j = 0; j < K; j++) {
        bool flag = 0;
        for(int k = 0; k < tmp[j].size(); k++) {
            if(flag) ans[j].push_front(tmp[j][k]);
            else ans[j].push_back(tmp[j][k]);
            flag = !flag;
        }
    }
    for(int j = 0; j < K; j++) {
        cout << ans[j][0].first;
        for(int k = 1; k < ans[j].size(); k++) 
            cout << " " << ans[j][k].first;
        cout << endl;
    }
    return 0;
}