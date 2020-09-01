#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    vector<int> v(N + 1); vector<int> judge(N + 1);
    for(int i = 1; i <= N; i++)
        scanf("%d", &v[i]);
    for(int i = 1; i <= N - 1; i++) {
        for(int j = i + 1; j <= N; j++) {
            fill(judge.begin(), judge.end(), 1);
            judge[i] = judge[j] = -1; // wolf
            vector<int> liars;
            for(int k = 1; k <= N; k++) 
                if(judge[abs(v[k])] * v[k] < 0) liars.push_back(k);
            if(liars.size() == 2 && judge[liars[0]] + judge[liars[1]] == 0) 
                printf("%d %d\n", i, j), exit(0);
        }
    }
    printf("No Solution\n");
    return 0;
}