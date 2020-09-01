#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 110;
int maze[110][110], d[110][110];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int main() {
    // freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            scanf("%d", &maze[i][j]);
    // bfs
    fill(d[0], d[0] + 110 * 110, -1);
    d[0][0] = 0;
    queue<pair<int, int>> q; q.push({0, 0});
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int x = p.first + dx[i], y = p.second + dy[i];
            if(maze[x][y] == 0 && x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1) {
                d[x][y] = d[p.first][p.second] + 1;
                q.push({x, y});
            }
        }
    }
    printf("%d", d[n - 1][m - 1]);
    return 0;
}