#include <iostream>
#include <vector>
using namespace std;
// 找出一个字符串中最长子串
// 首先一个循环，定位回文串的中心点（可能回文串是偶数，则定位中间点的左位置）
//  用另外一个循环进行向两边扫描，进行找出中间一个点，如果最长子串找到了，与最终的res进行比较
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0; i < s.size(); i++) {
            int l = i - 1, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
            if(res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
            if(res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
        }
        return res;
    }
};