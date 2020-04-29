#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool is_prime(int N) {
    if(N == 2 || N == 3) return true;
    for(int i = 2; i * i <= N; i++)
        if(N % i == 0) return false;
    return true;
}
map<int, int> m;
int main() {
    int N, K, tmp;
    cin >> N;
    vector<int> v(N + 1);
    for(int i = 1; i <= N; i++)
        cin >> v[i];
    cin >> K;
    while(K--) {
        cin >> tmp;
        int i = 1;
        while(i <= N && v[i] != tmp) i++;
        if(i == N + 1) printf("%04d: Are you kidding?\n", tmp);
        else {
            if(m[tmp]) {
                printf("%04d: Checked\n", tmp);
            } else {
                m[tmp] = 1;
                if(i == 1) printf("%04d: Mystery Award\n", tmp);
                else if(is_prime(i)) printf("%04d: Minion\n", tmp);
                else printf("%04d: Chocolate\n", tmp);
            }
        }
    }
    return 0;
}