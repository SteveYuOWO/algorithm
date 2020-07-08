#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    string str1, str2;
    unordered_map<char, bool> m;
    getline(cin, str1);
    getline(cin, str2);
    for(int i = 0; i < str1.length(); i++)
        m[toupper(str1[i])] = true;
    for(int i = 0; i < str2.length(); i++)
        m[toupper(str2[i])] = false;
    for(int i = 0; i < str1.length(); i++)
        if(m[toupper(str1[i])]) {
            cout << (char)toupper(str1[i]);
            m[toupper(str1[i])] = false;
        }
    system("pause");
    return 0;
}
