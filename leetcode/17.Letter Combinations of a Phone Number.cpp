#include <iostream>
#include <vector>
using namespace std;
// 这题是一道dfs, 我们可以通过进行递归进行产生式子
// 总复杂度是 O(4^n*n), 递归是一个4个路径的树 为4^n, 而vector的push_back则是一个O(n)复杂度
class Solution {
public:
    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        dfs(digits, 0, "");
        return ans;
    }
    void dfs(string& digits, int index, string tmp) {
        if(index == digits.size()) {
            if(tmp != "") ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < map[digits[index]-'0'].size(); i++) 
            dfs(digits, index + 1, tmp + map[digits[index]-'0'][i]);
    }
};