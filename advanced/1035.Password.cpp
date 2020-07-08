#include <iostream>
#include <map>
using namespace std;
map<char, char> m;
int main() {
    int N, modicoun = 0;
    string user, pw, res;
    scanf("%d", &N);
    m['l'] = 'L'; m['O'] = 'o'; m['1'] = '@'; m['0'] = '%';
    for(int j = 0; j < N; j++) {
        bool modi = false;
        cin >> user >> pw;
        for(int i = 0; i < pw.length(); i++){
            if(m[pw[i]] != 0) {
                pw[i] = m[pw[i]];
                modi = true;
            }
        }
        if(modi) {
            res = res + user + " " + pw + "\n";
            modicoun++;
        }
    }
    if(!modicoun) 
        if(N != 1) printf("There are %d accounts and no account is modified", N);
        else printf("There is 1 account and no account is modified");
    else printf("%d\n%s", modicoun, res.c_str());
    return 0;
}
