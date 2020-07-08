#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int sz) {
    if(sz < 2) return false;
    for(int i = 2; i * i <= sz; i++)
        if(sz % i == 0) return false;
    return true;
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int MSize, N, M, tmp;
    scanf("%d%d%d", &MSize, &N, &M);
    while(!isPrime(MSize)) MSize++;
    vector<int> ht(MSize, -1);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        bool insert = false;
        for(int j = 0; j < MSize; j++) {
            int pos = (tmp + j * j) % MSize;
            if(ht[pos] == -1) {
                ht[pos] = tmp;
                insert = true;
                break;
            }
        }
        if(insert == false) printf("%d cannot be inserted.\n", tmp);
    }
    double sum = 0;
    for(int i = 0; i < M; i++) {
        scanf("%d", &tmp);
        for(int j = 0; j <= MSize; j++) {
            sum++;
            int pos = (tmp + j * j) % MSize;
            if(tmp == ht[pos] || ht[pos] == -1) break;
        }
    }
    printf("%.1f\n", sum / M);
    return 0;
}
