#include <iostream>
using namespace std;
int N, cnt = 0; string tmp;
double sum = 0.0;
// 自动机解决数字判断
bool isLegal(string& s) {
    int i = 0;
    if(s[i] == '-') {
        i++; // 第一位是-
        if(i >= s.length() || !isdigit(s[i])) return false; // 第二位不是数字
    }
    while(i < s.length() && isdigit(s[i])) i++; // 过滤掉小数点前数字
    if(i == s.length()) return true; // 结束1
    if(s[i] == '.') i++; // 过滤. 
    int cnt = 2;
    while(cnt--)
        if(i < s.length() && isdigit(s[i])) i++; // 过滤掉小数点后2位数字
    return i == s.length(); // 如果到了最后，则返回true，否则返回false
}
int main() {
    cin >> N;
    while(N--) {
        cin >> tmp;
        if(isLegal(tmp) && stod(tmp) >= -1000 && stod(tmp) <= 1000) {
            cnt++;
            sum += stod(tmp);
        } else printf("ERROR: %s is not a legal number\n", tmp.c_str());
    }
    if(cnt == 0) printf("The average of 0 numbers is Undefined\n");
    else if(cnt == 1) printf("The average of 1 number is %.2lf\n", sum);
    else printf("The average of %d numbers is %.2lf\n", cnt, sum / (double)cnt);
    return 0;
}