#include <iostream>
#include <vector>
using namespace std;
/*
给定一个字符串，给定一个字符串类型的arr,
arr中每一个字符串代表一个贴纸，你可以把单个字符剪开使用，目的是拼出str来
返回多少个贴纸可以完成任务
例子：str = "babac", arr= {"ba", "c", "abcd"}
至少需要两张贴纸“ba”和“abcd”，因为使用这两张贴纸，含有2个a，2个b，1个c
*/
int minStick(string& str, vector<string>& v) {
    if(str == "") return 0;

    int ans = 1, next = 0;
    // 搞定第一张贴纸
    for(auto& x: v) {
        // 减去贴纸数量
        // int cur = minStick(nextRest, v);
        // next = min(next, cur);
// 
    }
    return 0;
}
int main() {
    
    return 0;
}
