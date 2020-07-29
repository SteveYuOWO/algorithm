#include <iostream>
using namespace std;
// 这题主要是进行找规律
// 从左边往右边，罗马数字总是找到最大的，进行标记，减去后继续找下一个
class Solution {
public:
    string intToRoman(int num) {
        int values[]={ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string reps[]={ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        for(int i=0; i<13; i++){
            while(num>=values[i]){
                num -= values[i];
                res += reps[i];
            }
        }
        return res;
    }
};