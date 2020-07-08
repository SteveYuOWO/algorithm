#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stu {
    string id;
    int score[4],r[4];
};
int choice;
bool cmp(stu s1, stu s2) {
    return s1.score[choice] > s2.score[choice];
}
vector<stu> v;
int main() {
    int M, N;
    cin >> M >> N;
    stu tmp;
    for(int i = 0; i < M; i++) {
        cin >> tmp.id >> tmp.score[0] >> tmp.score[1] >> tmp.score[2];
        tmp.score[3] = tmp.score[0] + tmp.score[1] + tmp.score[2];
        v.push_back(tmp);
    }
    for(choice = 0; choice < 4; choice++) {
        sort(v.begin(), v.end(), cmp);
        v[0].r[choice] = 1;
        for(int i = 1; i < M; i++)
            if(v[i].score[choice] == v[i-1].score[choice]) v[i].r[choice] = v[i-1].r[choice];
            else v[i].r[choice] = i + 1;
    }
    while(N--) {
        cin >> tmp.id;
        int i;
        for(i = 0; i < M; i++) if(tmp.id == v[i].id) break;
        if(i == M) {
            printf("N/A\n");
            continue;
        }
        int a = v[i].r[3],c = v[i].r[0],m = v[i].r[1],e = v[i].r[2];
        if(a <= c && a <= m && a <= e) printf("%d A\n", a);
        else if(c <= a && c <= m && c <= e) printf("%d C\n", c);
        else if(m <= c && m <= a && m <= e) printf("%d M\n", m);
        else if(e <= c && e <= m && e <= a) printf("%d E\n", e);
    }
    return 0;
}
