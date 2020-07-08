#include <iostream>
#include <vector>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    vector<vector<string>> v;
    string str, toPrint;
    for(int i = 0; i < 26; i++) {
        vector<string> tmp;
        for(int j = 0; j < 7; j++) {
            cin >> str;
            tmp.push_back(str);
        }
        v.push_back(tmp);
    }
    getline(cin, str); getline(cin, str);
    vector<string> words;
    for(int i = 0; i < str.length(); i++) {
        if(isupper(str[i])) {
            toPrint+= str[i];
        } else if(toPrint != ""){
            words.push_back(toPrint);
            toPrint = "";
        }
    }
    if(toPrint != "") words.push_back(toPrint);
    for(int i = 0; i < words.size(); i++) {
        for(int k = 0; k < 7; k++) {
            for(int j = 0; j < words[i].size(); j++) {
               if(j != words[i].size() - 1) printf("%s ", v[words[i][j] - 'A'][k].c_str());
               else printf("%s\n", v[words[i][j] - 'A'][k].c_str());
            }
        }
        if(i != words.size() - 1) printf("\n");
    }
    return 0;
}