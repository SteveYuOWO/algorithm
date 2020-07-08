#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string tmp, ans;
vector<string> v;
int main() {
    int N;
    scanf("%d\n", &N);
    for(int i = 0; i < N; i++) {
        getline(cin, tmp);
        reverse(tmp.begin(), tmp.end());
        v.push_back(tmp);
    }
    for(int i = 0; i < v[0].size(); i++){
        int cnt = 0;
        for(int j = 0; j < N; j++)
            if(v[j][i] == v[0][i]) cnt++;
            else break;
        if(cnt == N) ans = v[0][i] + ans;
        else break;
    }
    if(ans != "") cout << ans;
    else cout << "nai";
    return 0;
}
