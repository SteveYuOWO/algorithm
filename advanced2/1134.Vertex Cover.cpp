#include <iostream>
#include <unordered_set>
using namespace std;
int N, M, K, tmp, Nv;
pair<int, int> p[99999];
int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) 
        cin >> p[i].first >> p[i].second;
    cin >> K;
    while(K--) {
        cin >> Nv;
        unordered_set<int> s;
        while(Nv--) {
            cin >> tmp;
            s.insert(tmp);
        }
        bool flag = true;
        for(int i = 0; i < M; i++) {
            if(s.find(p[i].first) == s.end() && s.find(p[i].second) == s.end()) {
                flag = false;
                break;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}