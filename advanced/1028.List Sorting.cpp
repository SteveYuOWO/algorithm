#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int choose;
bool cmp(vector<string>& s, vector<string>& s2){
    return s[choose] == s2[choose] ? s[1] < s2[1]: s[choose] < s2[choose];
}
int main() {
    int M;
    cin >> M >> choose;
    vector<string> s[M];
    for(int  i= 0; i < M; i++){
        s[i].resize(4);
        cin >> s[i][1] >> s[i][2] >> s[i][3];
    }
    sort(s, s+M, cmp);
    for(int  i= 0; i < M; i++)
        printf("%s %s %s\n", s[i][1].data(),
               s[i][2].data(), s[i][3].data());
    return 0;
}
