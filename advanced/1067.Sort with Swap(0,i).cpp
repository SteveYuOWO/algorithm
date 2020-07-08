#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
map<int, int> m;
int N, cnt = 0, tmp;
int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &tmp);
        m[tmp] = i;
    }
    for(int i = 1; i < N; i++) {
        if(i != m[i]) {
            while(m[0] != 0) {
                swap(m[0], m[m[0]]);
                cnt++;
            }
            if(i != m[i]) {
                swap(m[0], m[i]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}