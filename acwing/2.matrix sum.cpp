#include <iostream>
using namespace std;

int arr[1010][1010];
int main() {
    int n, m ,q;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            scanf("%d", &arr[i][j]);

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + arr[i][j];

    while(q--) {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1]);
    }
    return 0;
}
