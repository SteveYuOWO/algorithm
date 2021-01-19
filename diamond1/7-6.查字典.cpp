#include <iostream>
#include <map>
using namespace std;
int main() {
    int N, tmp_i, M;
    cin >> N;
    string tmp;
    map<string, int> m;
    while(N--) {
        cin >> tmp >> tmp_i;
        m[tmp] = tmp_i;
    }
    cin >> M;
    while(M--) {
        cin >> tmp;
        if(m[tmp] != 0) cout << m[tmp] << endl;
        else cout << "Not Found" << endl;
    }
    return 0;
}