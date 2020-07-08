#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    unordered_map<int, vector<string>> m;
    int M, N, num, tmp;
    string name;
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        cin >> name >> num;
        while(num--) {
            cin >> tmp;
            m[tmp].push_back(name);
        }
    }
    for(int i = 1; i <= N; i++) {
        sort(m[i].begin(), m[i].end());
        printf("%d %d\n", i, m[i].size());
        for(int j = 0; j < m[i].size(); j++)
            printf("%s\n", m[i][j].c_str());
    }
    system("pause");
    return 0;
}
