#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
    string str, resKey;
    int resValue;
    unordered_map<string, int> m;
    getline(cin, str);
    for(int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);//转换小写字母
    int start = 0;
    for(int _end = 0; _end < str.length(); _end++) {
        string tmp = "";
        while(isalnum(str[_end])) _end++;
        if(++m[str.substr(start, _end - start)] > resValue){
            resKey = str.substr(start, _end - start);
            resValue = m[resKey];
        }
        while(!isalnum(str[_end])) _end++;
        start = _end;
    }
    cout << resKey << " " <<resValue;
    return 0;
}
