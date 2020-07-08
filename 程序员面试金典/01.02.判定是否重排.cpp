#include <iostream>
#include <algorithm>
using namespace std;
// 使用26个数组大小进行计数，复杂度O(n)
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        int a1[26] = {0}, a2[26] = {0};
        for(int i = 0; i < s1.length(); i++) {
            a1[s1[i]-'a']++;
            a2[s2[i]-'a']++;
        }
        for(int i = 0; i < 26; i++) 
            if(a1[i] != a2[i]) return false;
        return true;
    }
};
