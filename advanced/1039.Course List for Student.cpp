#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main() {
    int N, K, sid, num;
    string name;
    unordered_map<string, map<int,int>> m;
    cin >> N >> K;
    while(K--) {
        cin >> sid >> num;
        while(num--) {
            cin >> name;
            m[name][sid] = sid;
        }
    }
    while(N--) {
        cin >> name;
        cout << name << " " << m[name].size();
        for(auto it = m[name].begin(); it != m[name].end(); it++)
            cout << " " << it -> first;
        cout << endl;
    }
    return 0;
}
