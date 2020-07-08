#include <iostream>
using namespace std;
// 使用26个数组大小进行计数，复杂度O(n)
class Solution {
public:
    bool isUnique(string astr) {
        int arr[26] = {0};
        for(int i = 0; i < astr.length(); i++)
            arr[astr[i] - 'a']++;
        bool ret = true;
        for(int i = 0; i < 26; i++)
            if(arr[i] > 1) ret = false;
        return ret;
    }
};
