#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<char, bool> m;
int main() {
    string str, pattern, res;
    getline(cin, str); getline(cin, pattern);
    for(int i = 0; i < pattern.length(); i++) m[pattern[i]] = 1;
    for(int i = 0; i < str.length(); i++)
        if(!m[str[i]]) res += str[i];
    cout << res;
    return 0;
}
