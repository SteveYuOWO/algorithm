#include <iostream>
#include <vector>
using namespace std;
// 整数反转
// 注意附加条件，我们使用long long 存储后，要进行判别与 INT_MAX 和 INT_MIN 的大小
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