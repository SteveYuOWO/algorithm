#include <iostream>
#include <cstring>
#include <stack>
#include <map>
using namespace std;
char str[30];
string ans;
stack<char> op;
map<char, int> m; // 优先级别
// 数字直接输出，运算符入栈，如果比
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%s", str);
    m['-'] = m['+'] = 1; m['*'] = m['/'] = 2; // 存储优先级
    for(int i = 0; i < strlen(str); i++) {
        if(isdigit(str[i]) || str[i] == '.') {
            ans += ' ';
            while(i < strlen(str) && (isdigit(str[i]) || str[i] == '.')) 
                ans += str[i++];
            i--;
        }else if(str[i] == '(') op.push(str[i]);
        else if(str[i] == ')') {
            while(op.top() != '(') {
                ans = ans + ' ' + op.top();
                op.pop();
            }
            op.pop();
        }else if(op.empty()) op.push(str[i]);
        else if(m[str[i]] > m[op.top()]) op.push(str[i]);
        else {
            while(!op.empty() && m[str[i]] <= m[op.top()]) {
                ans = ans + ' ' + op.top();
                op.pop();
            }
            op.push(str[i]);
        }
    }
    while(!op.empty()) {
        ans = ans + ' ' + op.top();
        op.pop();
    }
    printf("%s\n", &ans.c_str()[1]);
    return 0;
}
