#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct peo {
    string id;
    int tal, vir, level, all;
};
bool cmp(peo& p1, peo& p2) {
    if(p1.level != p2.level) return p1.level < p2.level;
    if(p1.all != p2.all) return p1.all > p2.all;
    if(p1.vir != p2.vir) return p1.vir > p2.vir;
    return p1.id < p2.id;
}
int main() {
    int N, L, H;
    vector<peo> v;
    peo tmp;
    scanf("%d%d%d", &N, &L, &H);
    while(N--) {
        cin >> tmp.id >> tmp.vir >> tmp.tal;
        tmp.all  = tmp.tal + tmp.vir;
        if(tmp.tal >= L && tmp.vir >= L) {
            if(tmp.tal >= H && tmp.vir >= H) tmp.level = 1;
            else if(tmp.vir >= H) tmp.level = 2;
            else if(tmp.vir >= tmp.tal) tmp.level = 3;
            else tmp.level = 4;
            v.push_back(tmp);
        }
    }
    sort(v.begin(), v.end(), cmp);
    printf("%d\n", v.size());
    for(auto x: v) printf("%s %d %d\n", x.id.data(), x.vir, x.tal);
    return 0;
}
