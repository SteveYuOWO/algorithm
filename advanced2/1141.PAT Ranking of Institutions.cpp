#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int rank, cnt;
    char school[10];
    int score;
    double score_T, score_A, score_B;
    node():score(0), score_T(0), score_A(0), score_B(0), rank(0), cnt(0){}
};
unordered_map<string, node*> m;
vector<node> v;
bool cmp(node& n1, node& n2) {
    if(n1.score != n2.score) return n1.score > n2.score;
    if(n1.cnt != n2.cnt) return n1.cnt < n2.cnt;
    return strcmp(n1.school, n2.school) < 0;
}
int main() {
    char id[10], school[10];
    int N;
    double score;
    scanf("%d", &N);
    while(N--) {
        scanf("%s%lf%s", id, &score, school);
        for(int i = 0; i < strlen(school); i++) 
            school[i] = tolower(school[i]);
        if(m[school] == NULL) {
            m[school] = new node();
            strcpy(m[school]->school, school);
        }
        if(id[0] == 'T') m[school]->score_T += score;
        else if(id[0] == 'A') m[school]->score_A += score;
        else m[school]->score_B += score;
        m[school]->cnt++;
    }
    for(auto x: m) {
        x.second->score = floor(x.second->score_A + x.second->score_B / 1.5 + x.second->score_T * 1.5);
        v.push_back(*x.second);
    }
    sort(v.begin(), v.end(), cmp);
    v[0].rank = 1;
    for(int i = 1; i < v.size(); i++) {
        if((int)v[i].score == (int)v[i - 1].score) 
            v[i].rank = v[i - 1].rank;
        else v[i].rank = i + 1;
    }
    printf("%lu\n", v.size());
    for(int i = 0; i < v.size(); i++)
        printf("%d %s %d %d\n", v[i].rank, v[i].school, v[i].score, v[i].cnt);
    return 0;
}