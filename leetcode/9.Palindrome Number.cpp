#include <iostream>
using namespace std;
// 进行逆序x，如果逆序和原来的数字相等，则是回文，否则不是
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long y = 0;
        for(int i = x; i; i /= 10) 
            y = y * 10 + i % 10;
        return x == y;
    }
};