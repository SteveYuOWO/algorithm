#include <iostream>
#include <vector>
using namespace std;
int N, M, K, path[1010][1010] = {0}, a, b, arr[1010], in_degree[1010] = {0};
vector<int> ans;
int main() {
    cin >> N >> M;
    while(M--) {
        cin >> a >> b;
        path[a][b] = 1;
        in_degree[b]++;
    }
    cin >> K;
    for(int c = 0; c < K; c++){
        for(int i = 0; i < N; i++) cin >> arr[i];
        int cp[1010];
        memcpy(cp, in_degree, 1010 * sizeof(int));
        bool add = false;
        for(int i = 0; i < N; i++) {
            if(cp[arr[i]] == 0) {
                for(int j = 1; j <= N; j++) 
                    if(path[arr[i]][j]) cp[j]--;
            } else add = true;
        }
        if(add) ans.push_back(c);
    }
    cout << ans[0];
    for(int i = 1; i < ans.size(); i++)
        cout << " " << ans[i];
    return 0;
}