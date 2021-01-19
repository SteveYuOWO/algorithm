#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int main() {
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end(), greater<int>());
    int col, row;
    for(int i = 1; i * i <= N; i++)
        if(N % i == 0) col = i;
    row = N / col;
    vector<vector<int>> ans(row);
    for(int i = 0; i < row; i++) ans[i].resize(col, -1);
    int x = 0, y = 0, dir = 0, i = 0;// 0 右边 1 下面 2 左面 3 上面
    if(y + 1 >= col || ans[x][y + 1] != -1) dir = (dir + 1) % 4; // 开始方向可能朝下
    while(true) {
        if(i == v.size()) break;
        if(dir == 0) {
            ans[x][y++] = v[i++]; 
            if(y + 1 >= col || ans[x][y + 1] != -1) dir = (dir + 1) % 4;
        } else if(dir == 1) {
            ans[x++][y] = v[i++];
            if(x + 1 >= row || ans[x + 1][y] != -1) dir = (dir + 1) % 4;
        } else if(dir == 2) {
            ans[x][y--] = v[i++];
            if(y - 1 < 0 || ans[x][y - 1] != -1) dir = (dir + 1) % 4;
        } else {
            ans[x--][y] = v[i++];
            if(x - 1 < 0 || ans[x - 1][y] != -1) dir = (dir + 1) % 4;
        }
    }
    for(int i = 0; i < row; i++) {
        printf("%d", ans[i][0]);
        for(int j = 1; j < col; j++) 
            printf(" %d", ans[i][j]);
        putchar('\n');
    }
    return 0;
}