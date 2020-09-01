#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int N) {
    if(N <= 1) return false;
    for(int i = 2; i * i <= N; i++)
        if(N % i == 0) return false;
    return true;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int MSize, N, M, tmp;
    scanf("%d%d%d", &MSize, &N, &M);
    while(!isPrime(MSize)) MSize++;
    vector<int> hash(MSize, 0);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        bool notInsert = true;
        for(int j = 0; j < MSize; j++) {
            int x = (tmp + j * j) % MSize;
            if(hash[x] == 0) {
                hash[x] = tmp; notInsert = false; break;
            } 
        }
        if(notInsert) printf("%d cannot be inserted.\n", tmp);
    }
    int cnt = 0;
    for(int k = 0; k < M; k++) {
        scanf("%d", &tmp);
        for(int i = 0; i <= MSize; i++) {
            int x = (tmp + i * i) % MSize;
            cnt++;
            if(hash[x] == 0 || hash[x] == tmp) break;
        }
    }
    printf("%.1lf", (double)cnt / M);
    return 0;
}