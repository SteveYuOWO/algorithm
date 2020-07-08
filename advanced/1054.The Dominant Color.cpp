#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int M, N, S, max_num = 0;
    cin >> M >> N;
    string tmp, res;
    unordered_map<string, int> m;
    S = M * N;
    while(S--) {
        cin >> tmp;
        m[tmp]++;
    }
    vector<pair<string,int>> v(m.begin(), m.end());
    for(int i = 0; i < v.size(); i++){
        if(v[i].second > max_num) {
            max_num = v[i].second;
            res = v[i].first;
        }
    }
    cout << res << endl;
    return 0;
}
