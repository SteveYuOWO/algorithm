#include <iostream>
#include <unordered_map>
using namespace std;
int N, tmp;
unordered_map<int, bool> m;
int main() {
    cin >> N;
    while(N--) {
        cin >> tmp;
        m[tmp] = 1;
    }
    for(int i = 1; i < 101000; i++) {
        if(m[i] == 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}