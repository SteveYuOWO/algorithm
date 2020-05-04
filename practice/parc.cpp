#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
map<int, set<int>> G;
map<int, int> degree;
int main() {
    int N, tmp, cnt = 0;
    scanf("%d", &N);
    vector<int> v(N), ans;
    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
        if(v[i] > 0) {
            degree[v[i]] = 0; // 入度设置为0
            cnt++;
        }
    }
    for(int i = 0; i < N; i++) {
        if(v[i] > 0) {
            int tmp = v[i];
            while(tmp % N != i) {
                G[v[tmp % N]].insert(v[i]);
                tmp++;
                degree[v[i]]++;
            }
        }
    }
    int index = 0;
    while(index != cnt) {
        int min;
        for(auto x: degree) {
            if(x.second == 0) {
                min = x.first;
                break;
            }
        }
        degree[min]--;
        for(auto x: G[min]) degree[x]--;
        ans.push_back(min);
        index++;
    }
    printf("%d", ans[0]);
    for(int i = 1; i < cnt; i++)
        printf(" %d", ans[i]);
    return 0;
}