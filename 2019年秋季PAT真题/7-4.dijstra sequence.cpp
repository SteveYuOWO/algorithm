#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int SIZE = 1005;

struct node {
    int v, weight;

    bool operator<(node &x) {
        return weight < x.weight;
    }
};

bool visited[SIZE];
vector<node> adj[SIZE];
int nv, ne, k, dist[SIZE], target[SIZE];

bool dijkstra() {
    fill_n(dist + 1, nv, -1);
    dist[target[0]] = 0;
    fill_n(visited + 1, nv, false);

    for (int i = 0; i < nv; ++i) {
        int minDist = -1;

        // 找出没有visit过的距离起点最小的所有的点
        unordered_set<int> shortest;
        for (int j = 1; j <= nv; ++j)
            if (!visited[j] && dist[j] != -1) {
                if (minDist == -1 || minDist > dist[j]) {
                    minDist = dist[j];
                    shortest.clear();
                    shortest.insert(j);
                } else if (minDist == dist[j]) shortest.insert(j);
            }

        // 判断给出的序列的第i位是否在shortest中
        int u = target[i];
        if (!shortest.count(u)) return false;

        // 松弛
        visited[u] = true;
        for (auto &e: adj[u]) {
            int v = e.v, uvWeight = e.weight;
            if (!visited[v] && (dist[v] == -1 || dist[v] > dist[u] + uvWeight))
                dist[v] = dist[u] + uvWeight;
        }
    }

    return true;
}

int main() {
    cin >> nv >> ne;
    for (int i = 0; i < ne; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> k;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < nv; ++j) cin >> target[j];
        if (dijkstra()) cout << "Yes\n";
        else cout << "No\n";
    }
}
