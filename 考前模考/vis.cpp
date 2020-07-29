#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#define INF 99999999
using namespace std;
int N, K, tmpHappy, len, G[310][310] = {0};
bool vis[310] = {0};
char start[10], tmp[10], a[10], b[10];
unordered_map<string, int> road;
unordered_map<int, string> m;
unordered_map<int, int> happy;
// ans variable
int mindiscnt = 0, mindis = INF, maxHappy = -1, avgHappy = 0;
vector<string> ansPath;
void dfs(int index, vector<string>& path, int hap, int dis) {
    if(m[index] == "ROM") {
        if(dis < mindis) { // 路径小
            mindis = dis;
            mindiscnt = 1;
            maxHappy = hap;
            ansPath = path;
        } else if(dis == mindis) {
            mindiscnt++;
            if(hap > maxHappy) {
                maxHappy = hap;
                ansPath = path;
            } else if(hap == maxHappy) {
                if(path.size() < ansPath.size()) {
                    maxHappy = hap;
                    ansPath = path;
                }
            }
        }
        return;
    }
    vis[index] = true;
    for(int i = 0; i < N; i++) {
        if(G[index][i] && !vis[i]) {
            path.push_back(m[i]);
            dfs(i, path, hap + happy[i], dis + G[index][i]);
            path.pop_back();
        } 
    }
    vis[index] = false;
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d%s", &N, &K, start);
    road[start] = 0; m[0] = start; happy[0] = 0;
    for(int i = 1; i < N; i++) {
        scanf("%s%d", tmp, &tmpHappy);
        road[tmp] = i; m[i] = tmp;
        happy[i] = tmpHappy;
    }
    while(K--) {
        scanf("%s%s%d", a, b, &len);
        int ai =road[a]; int bi = road[b];
        G[ai][bi] = G[bi][ai] = len;
    }
    vector<string> vc;
    vc.push_back(start);
    dfs(road[start], vc, 0, 0);
    avgHappy = floor(maxHappy / (ansPath.size() - 1));
    printf("%d %d %d %d\n", mindiscnt, mindis, maxHappy, avgHappy);
    cout << ansPath[0];
    for(int i = 1; i < ansPath.size(); i++)
        cout << "->" << ansPath[i];
    return 0;
}