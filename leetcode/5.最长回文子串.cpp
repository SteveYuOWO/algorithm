#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string ans;
    string longestPalindrome(string s) {
        if(isPalindrome(s)) return s;
        dfs(s);
        return ans;
    }
    void dfs(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(isPalindrome(s.substr(i, s.size() - i))) {
                if(ans.size() < s.size() - i) ans = s.substr(i, s.size() - i);
                return;
            } else dfs(s.substr(i, s.size() - i));
            if(isPalindrome(s.substr(0, s.size() - i))) {
                if(ans.size() < s.size() - i) ans = s.substr(i, s.size() - i);
                return;
            } else dfs(s.substr(i, s.size() - i));
        }
    }
    bool isPalindrome(string s) {
        for(int i = 0; i < s.length() / 2; i++)
            if(s[i] != s[s.length() - i - 1]) return false;
        return true;
    }
};