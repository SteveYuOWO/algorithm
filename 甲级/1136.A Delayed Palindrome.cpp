#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string add(string a, string b) {
    int c = 0;
    int i = 0;
    string ans;
    while(i < a.length() && i < b.length()) {
        c += (a[i] - '0' + b[i] - '0');
        ans += (c % 10 + '0');
        c /= 10;
        i++;
    }
    while(i < a.length()) {
        c += (a[i] - '0');
        ans += (c % 10 + '0');
        c /= 10;
        i++;
    }
    while(i < b.length()) {
        c += (b[i] - '0');
        ans += (c % 10 + '0');
        c /= 10;
        i++;
    }
    if(c != 0) ans += (c + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}
bool isPalindrome(string s) {
    for(int i = 0; i < s.length() >> 1; i++) 
        if(s[i] != s[s.length() - i - 1]) return false;
    return true;
}
int main() {
    char asc[10000], desc[10000];
    string tmp;
    cin >> tmp;
    if(isPalindrome(tmp)) {
        printf("%s is a palindromic number.\n", tmp.c_str());
        exit(0);
    }
    for(int i = 0; i < 10; i++) {
        strcpy(asc, tmp.c_str());
        strcpy(desc, asc);
        reverse(desc, desc + strlen(desc));
        tmp = add(asc, desc);
        printf("%s + %s = %s\n", asc, desc, tmp.c_str());
        if(isPalindrome(tmp)) {
            printf("%s is a palindromic number.\n", tmp.c_str());
            exit(0);
        }
    }
    printf("Not found in 10 iterations.\n");
    return 0;
}