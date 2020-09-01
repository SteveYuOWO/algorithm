#include <iostream>
#include <cctype>
#include <stack>
using namespace std;
string str, ans; 
stack<int> s;
int _end;
void parse() {
    if(s.empty()) return;
    int start = s.top(); s.pop();
    int dig_start = ++start;
    while(start < _end && isdigit(str[start])) start++;
    int num = stoi(str.substr(dig_start, start - dig_start));
    int pha_start = ++start;
    while(start < _end && isalpha(str[start])) start++;
    cout << str.substr(pha_start, start - dig_start) << endl;
}
int main() {
    freopen("in.txt", "r", stdin);
    cin >> str;
    int i = 0;
    while(i < str.size() && str[i] != '[') ans += str[i++];
    while(i < str.size()) {
        if(str[i] == '[') s.push(i);
        if(str[i] == ']') _end = i, parse();
        i++;
    }
    return 0;
}