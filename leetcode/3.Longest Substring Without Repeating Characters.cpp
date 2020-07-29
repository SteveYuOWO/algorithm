#include <iostream>
#include <unordered_map>
using namespace std;
// 这道题目使用双指针和滑动窗口算法，我们使用每次将unordered_map中逐步放s[i],
// 当s[i]有重复的（即s[i] >= 2)，则把j++，并且把s[i]清空。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int res = 0;
        for(int i = 0, j = 0; i < s.size(); i++) {
            m[s[i]]++;
            while(m[s[i]] > 1) {
                m[s[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return  res;
    }
};