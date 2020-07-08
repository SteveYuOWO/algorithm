#include <iostream>
#include <map>
using namespace std;
bool isPrime(int N) {
    if(N <= 1) return false;
    for(int i = 2; i * i <= N; i++)
        if(N % i == 0) return false;
    return true;
}
int main() {
    int M, N, tmp;
    map<int, bool> m;
    scanf("%d%d", &M, &N);
    while(!isPrime(M)) M++;
    while(N--) {
        scanf("%d", &tmp);
        bool out = false;
        for(int i = 0; i < M; i++) {
            if(m[(i * i + tmp) % M] == false) {
                m[(i * i + tmp) % M] = true;
                printf("%d", (i * i + tmp) % M);
                out = true;
                break;
            }
        }
        if(!out) printf("-");
        if(N != 0) printf(" ");
    }
    return 0;
}
