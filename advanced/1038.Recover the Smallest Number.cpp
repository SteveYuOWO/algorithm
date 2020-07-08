#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string s1, string s2) {
    return s1 + s2 < s2 + s1;
}
int main(){
    int N;
    cin >> N;
    vector<string> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    string res;
    for(int i = 0; i < N; i++)
        res += v[i];
    while(res.length() != 0 && res[0] == '0')
        res.erase(res.begin());
    if(res.length() == 0) cout << 0;
    else cout << res;
	return 0;
}
