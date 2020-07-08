#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct peo {
    string name;
    int score;
};
vector<peo> v;
bool cmp(peo& p1, peo& p2) {
    return p1.score == p2.score ? p1.name < p2.name: p1.score > p2.score;
}
int main() {
    int N, low , high, flag = 0;
    string tmp1, tmp2;
    peo tmp;
    scanf("%d", &N);
    while(N--) {
        cin >> tmp1 >> tmp2 >> tmp.score;
        tmp.name = tmp1 + " " + tmp2;
        v.push_back(tmp);
    }
    scanf("%d%d", &low, &high);
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++)
        if(v[i].score >= low && v[i].score <= high){
            cout << v[i].name << endl;
            flag = 1;
        }
    if(!flag) cout << "NONE" << endl;

    system("pause");
    return 0;
}
