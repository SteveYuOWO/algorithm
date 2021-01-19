#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void output(vector<int>& v) {
    printf("%d", v[0]);
    for(int i = 1; i < v.size(); i++)
        printf(" %d", v[i]);
    putchar('\n');
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> v(N), tmp;
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    for(int i = 0; i < N; i++) {
        tmp.push_back(v[i]);
        if(tmp.size() == M) {
            if(ans.size() % 2 == 1) 
                reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            tmp.clear();
        }
    }
    if(tmp.size() != 0) {
        if(ans.size() % 2 == 1) 
                reverse(tmp.begin(), tmp.end());
        ans.push_back(tmp);
    }
    for(int i = 0; i < ans.size(); i++)
        output(ans[i]);
    return 0;
}
