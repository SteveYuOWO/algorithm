#include <iostream>
using namespace std;
class Solution {
public:
    string compressString(string S) {
        char ch = S[0]; int cnt = 1;
        string ans;
        for(int i = 1; i < S.size(); i++) {
            if(S[i] == ch) cnt++;
            else {
                // ans = ans + ch + to_string(cnt); 超时
                ans += ch + to_string(cnt); // 通过，+= 比 + 快很多
                ch = S[i];
                cnt = 1;
            }
        }
        ans = ans + ch + to_string(cnt);
        return ans.size() >= S.size() ? S: ans;
    }
};