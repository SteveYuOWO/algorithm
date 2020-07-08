#include <iostream>
#include <algorithm>
using namespace std;
struct peo {
    string name;
    int age, net_worth;
}v[100005];
int N, K, M, after_m, _max, _min, p = 0;
bool cmp(peo p1, peo p2) {
    if(p1.net_worth != p2.net_worth) return p1.net_worth > p2.net_worth;
    if(p1.age != p2.age) return p1.age < p2.age;
    return p1.name < p2.name;
}
int main() {
    scanf("%d%d", &N, &K);
    while(N--) {
        v[p].name.resize(10);
        scanf("%s%d%d", v[p].name.c_str(), &v[p].age, &v[p].net_worth);
        p++;
    }
    sort(v, v + p, cmp);
    for(int i = 1; i <= K; i++) {
        scanf("%d%d%d", &M, &_min, &_max);
        printf("Case #%d:\n", i);
        after_m = M;
        for(int j = 0; j < p; j++)
            if(v[j].age >= _min && v[j].age <= _max)
                if(after_m--) printf("%s %d %d\n", v[j].name.c_str(), v[j].age, v[j].net_worth);
                else break;
        if(M == after_m) printf("None\n");
    }
    system("pause");
    return 0;
}
