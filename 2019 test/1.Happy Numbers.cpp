#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int N, tmp;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &tmp);
        unordered_map<int, bool> m;
        m[tmp] = 1;
        int happy = 0;
        while(tmp != 1) {
            string s = to_string(tmp);
            tmp = 0;
            for(int i = 0; i < s.size(); i++) 
                tmp += pow((s[i] - '0'), 2);
            if(m[tmp] == 1) break;
            else m[tmp] = 1;
            happy++;
        }
        printf("%d\n", tmp == 1 ? happy: tmp);
    }
    return 0;
}
