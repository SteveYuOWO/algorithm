#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct stu {
    char name[30] = {0};
    int Gp = -1, Gm = -1, Gf = -1, G = -1;
};
bool cmp(stu& s1, stu& s2) {
    return s1.G == s2.G ? strcmp(s1.name, s2.name) < 0 : s1.G > s2.G;
}
map<string, stu*> m;
int main() {
    int P, M, N;
    char a[30]; double b;
    scanf("%d%d%d", &P, &M, &N);
    while(P--) {
        scanf("%s%lf", a, &b);
        if(m[a] == NULL) m[a] = new stu();
        strcpy(m[a]->name, a);
        m[a]->Gp = b;
    }
    while(M--) {
        scanf("%s%lf", a, &b);
        if(m[a] == NULL) m[a] = new stu();
        strcpy(m[a]->name, a);
        m[a]->Gm = b;
    }
    while(N--) {
        scanf("%s%lf", a, &b);
        if(m[a] == NULL) m[a] = new stu();
        strcpy(m[a]->name, a);
        m[a]->Gf = b;
    }
    vector<stu> ans;
    for(auto x: m) {
        if(x.second->Gp >= 200) {
            if(x.second->Gm > x.second->Gf) x.second->G = round(x.second->Gm * 0.4 + x.second->Gf * 0.6);
            else x.second->G = x.second->Gf;
            if(x.second->G >= 60) ans.push_back(*x.second);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for(auto x: ans) {
        printf("%s %d %d %d %d\n", x.name, x.Gp, x.Gm, x.Gf, x.G);
    }
    return 0;
}