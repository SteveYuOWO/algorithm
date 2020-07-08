#include <iostream>
#include <vector>
using namespace std;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int T, M, N, tmp;
    scanf("%d%d%d", &T, &M, &N);
    vector<int> hashTable(T, -1);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        for(int k = 0; k < T; k++) {
            if(hashTable[(tmp % M + k) % T] == -1) {
                hashTable[(tmp % M + k) % T] = tmp;
                break;
            }
        }
    }
    double sum = 0;
    for(int i = 0; i < M; i++) {
        for(int k = 0; k <= T; k++) {
            sum++;
            if(hashTable[(i + k) % T] == -1) break;
        }
    }
    printf("%.1f", sum / M);
    return 0;
}