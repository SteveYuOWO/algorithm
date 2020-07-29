#include <iostream>
#include <vector>
using namespace std;
// 动态规划(延时分析法)

// 思考方式： 1.状态表示  2.状态计算
// 1.状态表示 f(im j) 
// 集合 所有 S(1 ~ i) 和 P (1 ~ j) 的匹配方案
// 属性 bool 是否存在一个合法方案

// 2. 状态计算
// P(j) 不是 * 直接匹配
// f(i, j) = f(i, j - 2) | f(i - 1, j)
class Solution {
public:
    vector<vector<int>>f;
    int n, m;
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        f = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        return dp(0, 0, s, p);
    }
    bool dp(int x, int y, string &s, string &p) {
        if (f[x][y] != -1) return f[x][y];
        if (y == m)
            return f[x][y] = x == n;
        bool first_match = x < n && (s[x] == p[y] || p[y] == '.');
        bool ans;
        if (y + 1 < m && p[y + 1] == '*')
        {
            ans = dp(x, y + 2, s, p) || first_match && dp(x + 1, y, s, p);
        }
        else
            ans = first_match && dp(x + 1, y + 1, s, p);
        return f[x][y] = ans;
    }
};