#include <iostream>
#include <string>
using namespace std;
int main() {
    int N; string s;
    cin >> N;
    while(N--) {
        cin >> s;
        int a = stoi(s.substr(0, s.length() / 2));
        int b = stoi(s.substr(s.length() / 2, s.length() / 2));
        int c = stoi(s);
        printf("%s\n", a * b == 0 ? "No" : (c % (a * b)) == 0 ? "Yes" : "No");
    } 
}