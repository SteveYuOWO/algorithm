#include <iostream>
#include <vector>
using namespace std;
// 先去除空格
// 再判定符号
// 之后读到long long 中
// 最后和 INT_MAX 和 INT_MIN 进行比较，最后返回
class Solution {
public:
    int myAtoi(string str) {
        long long i = 0, ans = 0, flag = 1;
        while(i < str.size() && str[i] == ' ') i++;
        if(str[i] == '+' || str[i] == '-') {
            if(str[i] == '-') flag = -1;
            i++;
        }
        while(i < str.size() && isdigit(str[i])) {
            ans = ans * 10 + (str[i] - '0');
            i++;
            if(ans > INT_MAX) break;
        }
        ans *= flag;
        if(ans < INT_MIN) return INT_MIN;
        if(ans > INT_MAX) return INT_MAX;
        return ans;
    }
};