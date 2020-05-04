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
    int MSize, N, M, tmp;
    cin >> MSize >> N >> M;
    while(!isPrime(MSize)) MSize++;
    vector<int> hash(MSize, 0);
    while(N--) {
        cin >> tmp;
        int flag = true;
        for(int i = 0; i < MSize; i++) {
            if(hash[(tmp + i * i) % MSize] == 0) {
                hash[(tmp + i * i) % MSize] = tmp;
                flag = false;
                break;
            }
        }
        if(flag) printf("%d cannot be inserted.\n", tmp);
    }
    int cnt = 0;
    for(int c = 0; c < M; c++) {
        cin >> tmp;
        for(int i = 0; i <= MSize; i++) {
            cnt++;
            if(hash[(tmp + i * i) % MSize] == tmp ||
                hash[(tmp + i * i) % MSize] == 0) 
                break;
        }
    }
    printf("%.1lf", (double)cnt / M);
    return 0;
}

