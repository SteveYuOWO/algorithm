#include <iostream>
#include <deque>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    deque<int> d1(N), d2(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &d1[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &d2[i]);
    int ans;
    while(N--) {
        if(d1.size() != 0 && d2.size() != 0) {
            if(d1[0] < d2[0]) {
                ans = d1.front();
                d1.pop_front();
            }
            else {
                ans = d2.front();
                d2.pop_front();
            }
        } else if(d1.size() != 0) {
            ans = d1.front();
            d1.pop_front();
        }
        else {
            ans = d2.front();
            d2.pop_front();
        }
    }
    printf("%d\n", ans);
    return 0;
}