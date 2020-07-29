#include <iostream>
#include <vector>
using namespace std;
// 我们找最长前缀的时候，只要进行遍历，进行追加pre字符串，即可
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string pre = "";
        for(int i = 0; ; i++) {
            if(i == strs[0].size()) return pre;
            for(int j = 1; j < strs.size(); j++) {
                if(i == strs[j].size()) return pre;
                if(strs[j][i] != strs[j - 1][i]) {
                    return pre;
                }
            }
            pre += strs[0][i];
        }
        return pre;
    }
};