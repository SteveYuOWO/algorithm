#include <iostream>
using namespace std;
string cal(string s) {
    string ans = "";
    char ch = s[0], cnt = 1;
    for(int i = 1; i < s.length(); i++) {
        if(s[i] != s[i - 1]) {
            ans += ch;
            ans += (cnt + '0');
            ch = s[i];
            cnt = 1;
        } else cnt++;
    }
    ans += ch;
    ans += (cnt + '0');
    return ans;
}
int main() {
    string D; int N;
    cin >> D >> N;
    while(--N) D = cal(D);
    cout << D;
    return 0;
}