#include <iostream>
#include <sstream>
using namespace std;
int main() {
    int N, tmp;
    string str;
    string ge[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string shi[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    cin >> N;
    getline(cin, str);
    while(N--) {
        getline(cin, str);
        if(isdigit(str[0])) {
            tmp = stoi(str);
            int shin = tmp / 13;
            int gen = tmp % 13;
            if(gen == 0 && shin == 0) cout << "tret" << endl;
            else {
                if(shin != 0) cout << shi[shin];
                if(shin != 0 && gen != 0) cout << " ";
                if(gen != 0) cout << ge[gen];
                cout << endl;
            }
        }else {
            stringstream ss;
            ss << str;
            int ans = 0;
            while(ss >> str) {
                for(int i = 1; i <= 12; i++){
                    if(shi[i] == str) ans += (13 * i);
                    if(ge[i] == str) ans += i;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
