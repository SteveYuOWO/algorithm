#include <iostream>
#include <vector>
using namespace std;
// 行数为 n
// 公差 2n - 2 首项 0 的等差数列
// 公差 2n - 2 首项 1 的等差数列 和 首项 2(n + 1) - 4 等差数列
// 公差 2n - 2 首项 2 的等差数列 和 首项 2(n + 1) - 3 等差数列
// .
// .
// .
// 公差 2n - 2 首项 n - 1 的等差数列

// 注意提交的时候有个问题，就是n == 1的时候，会直接返回原序列就可以了
class Solution {
public:
    string convert(string s, int n) {
        string res;
        if(n == 1) return s;
        for(int i = 0; i < n; i++) {
            if(i == 0 || i == n - 1) {
                for(int j = i; j < s.size(); j += 2 * n - 2) 
                    res += s[j];
            } else {
                for(int j = i, k = 2 * n - 2 - i; j < s.size() || k < s.size(); j += 2 * n - 2, k += 2 * n - 2) {
                    if(j < s.size()) res += s[j];
                    if(k < s.size()) res += s[k];
                }
            }
        }
        return res;
    }
};