#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int N, M, a, b;
int data[20][10100] = {0}, out[20] = {0};
unordered_set<int> s;
bool judge(int d) {
    for(auto x: s) 
        if(s.find(x + d) != s.end()) return true;
    return false;
}
int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d", &a, &b, &N, &M);
    s.insert(a); s.insert(b);
    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= M; j++) 
            scanf("%d", &data[i][j]);
    for(int j = 1; j <= M; j++) {
        for(int i = 1; i <= N; i++) {
            if(out[i]) continue; 
            int d = data[i][j];
            if(s.find(d) != s.end() || !judge(d)) {
                out[i] = 1;
                printf("Round #%d: %d is out.\n", j, i);
            } else s.insert(d);
        }
    }
    vector<int> win;
    for(int i = 1; i <= N; i++) 
        if(!out[i]) win.push_back(i);
    if(win.size() == 0) printf("No winner.\n");
    else {
        printf("Winner(s):");
        for(auto x: win) printf(" %d", x);
    }
    return 0;
}